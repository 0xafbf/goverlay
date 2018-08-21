{
    "targets": [
        {
            "target_name": "electron_overlay",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "include_dirs": [
                "./src",
                "./src/3rd",
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS', 'UNICODE'],
            "sources": [
                "./src/ipc/tinyipc.h",
                "./src/ipc/ipcmsg.h",
                "./src/ipc/ipclink.h",
                "./src/ipc/ipclink.cc",
                "./src/ipc/ipccenter.h",
                "./src/ipc/ipccenter.cc",
                "./src/utils.hpp",
                "./src/overlay.hpp",
                "./src/overlay.cc",
                "./src/windll.hpp",
                "./src/node_async_call.h",
                "./src/node_async_call.cc",
                "./src/message/nlohmann/json.hpp"
                "./src/message/gmessage.hpp"
                "./src/n-utils.hpp",
                "./src/main.cc"
            ],
        }
    ]
}
