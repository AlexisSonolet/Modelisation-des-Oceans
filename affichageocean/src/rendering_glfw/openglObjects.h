/*
 * openglObjects.h
 *
 *  Created on: 28 mars 2019
 *      OpenGL Template Author: Briac
 */

#ifndef OPENGLOBJECTS_H_
#define OPENGLOBJECTS_H_

#include <vector>
#include <map>

#include "glad/glad.h"
#include "linmath.h"

class VBO {
public:
	VBO(GLuint type);
	virtual ~VBO();

	void bind();
	void unbind();
	void storeData(const GLvoid* data, GLsizeiptr dataSize, GLuint usage);
	void updateData(const GLvoid* data, GLsizeiptr dataSize);

private:
	GLuint ID;
	GLuint type;

};

class VAO {
public:
	VAO();
	virtual ~VAO();

	void bind();
	void unbind();

	uint32_t getIndexCount() {
		return indexCount;
	}

	VBO* getIndexVBO() {
		return indexVBO;
	}

	std::vector<VBO*>& getAttributeVBOs() {
		return vbos;
	}

	void bindAttribute(uint32_t attribute);
	void unbindAttribute(uint32_t attribute);

	void createIndexBuffer(uint32_t* indices, uint32_t indexCount);
	void createFloatAttribute(uint32_t attribNumber, float* data,
			uint32_t dataLength, uint32_t size, GLenum usage = GL_STATIC_DRAW);
	void createIntAttribute(uint32_t attribNumber, int32_t* data,
			uint32_t dataLength, uint32_t size);

private:
	GLuint ID;
	VBO* indexVBO;
	uint32_t indexCount;

	std::vector<VBO*> vbos;

};

class Shader {
public:
	Shader(const char* vertexFilePath, const char* fragmentFilePath);
	Shader(const char* vertexFilePath, const char* geometryFilePath,
			const char* fragmentFilePath);
	virtual ~Shader();

	void start();
	void stop();
	void finishInit();

	void bindVertexAttribute(GLuint attribute, const char* variableName);

	void bindFragDataLocation(GLuint colorAttachment, const char* variableName);

	void connectTextureUnit(const std::string& sampler_name, GLint value);

	void loadInt(const std::string& name, GLint value);
	void loadFloat(const std::string& name, float value);
	void loadVec2(const std::string& name, vec2 v);
	void loadVec3(const std::string& name, vec3 v);
	void loadMat4(const std::string& name, mat4x4 mat);

	GLint operator[](const std::string& name) {
		return uniforms[name];
	}

	void init_uniforms(std::initializer_list<std::string> names);

private:
	GLint programID;
	GLint vertexShaderID;
	GLint geometryShaderID;
	GLint fragmentShaderID;
	std::map<std::string, GLint> uniforms;

	GLint loadFromFile(const char* filePath, GLuint programType);
	GLint getUniformLocation(const char* variableName);

	GLint findUniformLoc(const std::string& name) {
		const auto& it = uniforms.find(name);
		if (it == end(uniforms)) {
			throw "Error, unknown uniform variable name: " + name;
		}
		return it->second;
	}

};

#endif /* OPENGLOBJECTS_H_ */
