{
    "targets": [
        {
            "target_name": "base64",
            "sources": [
                "base64.cc"
            ]
        },
        {
            "target_name": "after_build",
            "type": "none",
            "dependencies": [
                "base64"
            ],
            "actions": [
                {
                    "action_name": "symlink",
                    "inputs": [
                        "build/Release/base64.node"
                    ],
                    "outputs": [
                        "base64.node"
                    ],
                    "action": ["ln", "-s", "build/Release/base64.node", "base64.node"]
                }
            ]
        }
    ]
}
