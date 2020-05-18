# Modélisation & C++

Programme de modélisation de la surface des océans.

## Débug sur VSCode
Dans `launch.json` :
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Activer l'impression en mode Pretty pour gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```
