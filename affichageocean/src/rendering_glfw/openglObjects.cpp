/*
 * openglObjects.c
 *
 *  Created on: 28 mars 2019
 *      Author: Briac
 */

#include "openglObjects.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h> //_getcwd for windows

VAO::VAO() :
		vbos() {
	glGenVertexArrays(1, &ID);
	indexVBO = NULL;
	indexCount = 0;
}

VAO::~VAO() {
	delete this->indexVBO;
	for (VBO* vbo : this->vbos) {
		delete vbo;
	}

	glDeleteVertexArrays(1, &ID);
}

VBO::VBO(GLuint type) {
	glGenBuffers(1, &ID);
	this->type = type;
}

VBO::~VBO() {
	glDeleteBuffers(1, &ID);
}

void VBO::bind() {
	glBindBuffer(type, ID);
}

void VBO::unbind() {
	glBindBuffer(type, 0);
}

void VBO::storeData(const GLvoid* data, GLsizeiptr dataSize, GLuint usage) {
	glBufferData(type, dataSize, data, usage);
}

void VBO::updateData(const GLvoid* data, GLsizeiptr dataSize) {
	glBufferSubData(type, 0, dataSize, data);
}

void VAO::bind() {
	glBindVertexArray(ID);
}

void VAO::unbind() {
	glBindVertexArray(0);
}

void VAO::bindAttribute(uint32_t attribute) {
	glEnableVertexAttribArray(attribute);
}

void VAO::unbindAttribute(uint32_t attribute) {
	glDisableVertexAttribArray(attribute);
}

void VAO::createIndexBuffer(uint32_t* indices, uint32_t indexCount) {
	VBO* indexVBO = new VBO(GL_ELEMENT_ARRAY_BUFFER);
	indexVBO->bind();
	indexVBO->storeData(indices, indexCount * sizeof(uint32_t), GL_STATIC_DRAW);
	//VBO_Unbind(indexVBO); DO NOT UNBIND !!

	this->indexVBO = indexVBO;
	this->indexCount = indexCount;
}

void VAO::createFloatAttribute(uint32_t attribNumber, float* data,
		uint32_t dataLength, uint32_t size, GLenum usage) {
	VBO* vbo = new VBO(GL_ARRAY_BUFFER);
	vbo->bind();
	vbo->storeData(data, dataLength * sizeof(float), usage);
	glVertexAttribPointer(attribNumber, size, GL_FLOAT, GL_FALSE,
			size * sizeof(float), 0);
	vbo->unbind();

	vbos.push_back(vbo);
}

void VAO::createIntAttribute(uint32_t attribNumber, int32_t* data,
		uint32_t dataLength, uint32_t size) {
	VBO* vbo = new VBO(GL_ARRAY_BUFFER);
	vbo->bind();
	vbo->storeData(data, dataLength * sizeof(int32_t), GL_STATIC_DRAW);
	glVertexAttribPointer(attribNumber, size, GL_INT, GL_FALSE,
			size * sizeof(int32_t), 0);
	vbo->unbind();

	vbos.push_back(vbo);
}

/**
 * Construit un nouveau shader.
 * Ne pas oublier d'appeler:
 *     -Shader::bindVertexAttribute   ***
 *     -Shader::bindFragDataLocation  ***
 *     -Shader::finishInit
 *     -Shader::getUniformLocation    ***
 *     -Shader::start
 *     -Shader::connectTextureUnit    ***
 *     -Shader::stop
 * de fa�on � finaliser l'initialisation du shader.
 *
 */
Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) {

	vertexShaderID = loadFromFile(vertexFilePath,
	GL_VERTEX_SHADER);
	geometryShaderID = -1;
	fragmentShaderID = loadFromFile(fragmentFilePath,
	GL_FRAGMENT_SHADER);

	programID = glCreateProgram();

	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

}

/**
 * Construit un nouveau shader.
 * Ne pas oublier d'appeler:
 *     -Shader::bindVertexAttribute   ***
 *     -Shader::bindFragDataLocation  ***
 *     -Shader::finishInit
 *     -Shader::getUniformLocation    ***
 *     -Shader::start
 *     -Shader::connectTextureUnit    ***
 *     -Shader::stop
 * de fa�on � finaliser l'initialisation du shader.
 *
 */
Shader::Shader(const char* vertexFilePath, const char* geometryFilePath,
		const char* fragmentFilePath) {

	vertexShaderID = loadFromFile(vertexFilePath,
	GL_VERTEX_SHADER);
	geometryShaderID = loadFromFile(geometryFilePath,
	GL_GEOMETRY_SHADER);
	fragmentShaderID = loadFromFile(fragmentFilePath,
	GL_FRAGMENT_SHADER);

	programID = glCreateProgram();

	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, geometryShaderID);
	glAttachShader(programID, fragmentShaderID);

}

void Shader::finishInit() {
	glLinkProgram(programID);
	GLint linkRes = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &linkRes);
	if (linkRes == GL_FALSE) {
		std::cerr << "Problème lors du linkage du shader " << std::endl;
	}
	glValidateProgram(programID);
}

Shader::~Shader() {
	glUseProgram(0);
	glDetachShader(programID, vertexShaderID);
	if (geometryShaderID != -1)
		glDetachShader(programID, geometryShaderID);
	glDetachShader(programID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	if (geometryShaderID != -1)
		glDeleteShader(geometryShaderID);
	glDeleteShader(fragmentShaderID);

	glDeleteProgram(programID);
}

void Shader::start() {
	glUseProgram(programID);
}

void Shader::stop() {
	glUseProgram(0);
}

GLint Shader::loadFromFile(const char* filePath, GLuint programType) {

	std::vector<GLchar> buffer;

	FILE* f = fopen(filePath, "r");
	if (f == NULL) {
		std::cerr << "Le fichier " << filePath << "est introuvable !"
				<< std::endl;
		char buff[1024];
		_getcwd((char*) &buff, 1024); //current working directory
		std::cerr << "Dernier emplacement cherché: " << buff << "\\" << filePath
				<< std::endl;
		exit(EXIT_FAILURE);
	}

	char c = ' ';
	while ((c = fgetc(f)) != EOF) {
		buffer.push_back(c);
	}
	buffer.push_back('\0');

	fclose(f);

	GLchar* programSource = (GLchar*) malloc(buffer.size());
	for (uint32_t i = 0; i < buffer.size(); i++) {
		programSource[i] = buffer[i];
	}

	GLint shaderID = glCreateShader(programType);
	GLint* length = NULL;
	glShaderSource(shaderID, 1, (const GLchar* const *) &programSource, length);
	glCompileShader(shaderID);

	GLint status = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		std::cerr << "Erreur lors de la compilation de " << filePath << " :"
				<< std::endl;
		GLint sizeNeeded = 0;
		glGetShaderiv(shaderID, GL_SHADER_SOURCE_LENGTH, &sizeNeeded);
		GLchar* strbuff = (GLchar*) malloc(sizeNeeded);

		glGetShaderInfoLog(shaderID, sizeNeeded, NULL, strbuff);
		std::cerr << strbuff << std::endl;
		free(strbuff);

		exit(EXIT_FAILURE);
	}

	free(programSource);
	programSource = NULL;

	return shaderID;
}

void Shader::init_uniforms(std::initializer_list<std::string> names) {
	start();
	for (auto& name : names) {
		GLint loc = getUniformLocation(name.c_str());
		std::cout << "Uniform location of " << name << " = " << loc
				<< std::endl;

		if (loc == -1)
			std::cout
					<< " 	--> The uniform variable name is either incorrect or the uniform variable is not used"
					<< std::endl;

		uniforms[name] = loc;
	}
	stop();
}

void Shader::bindVertexAttribute(GLuint attribute, const char* variableName) {
	glBindAttribLocation(programID, attribute, variableName);
}

void Shader::bindFragDataLocation(GLuint colorAttachment,
		const char* variableName) {
	glBindFragDataLocation(programID, colorAttachment, variableName);
}

GLint Shader::getUniformLocation(const char* variableName) {
	return glGetUniformLocation(programID, variableName);
}

void Shader::connectTextureUnit(const std::string& sampler_name, GLint value) {
	loadInt(sampler_name, value);
}

void Shader::loadInt(const std::string& name, GLint value) {
	glUniform1i(findUniformLoc(name), value);
}

void Shader::loadFloat(const std::string& name, float value) {
	glUniform1f(findUniformLoc(name), value);
}

void Shader::loadVec2(const std::string& name, vec2 v) {
	glUniform2f(findUniformLoc(name), v[0], v[1]);
}

void Shader::loadVec3(const std::string& name, vec3 v) {
	glUniform3f(findUniformLoc(name), v[0], v[1], v[2]);
}

void Shader::loadMat4(const std::string& name, mat4x4 mat) {
	static float buffer[16];

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			buffer[4 * x + y] = mat[x][y];
		}
	}

	glUniformMatrix4fv(findUniformLoc(name), 1,
	GL_FALSE, (const GLfloat *) &buffer);
}

