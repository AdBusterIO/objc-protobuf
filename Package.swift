// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Protobuf",
    products: [
        .library(
            name: "Protobuf",
            targets: [
                "Protobuf",
                "Protobuf+JSONFormat",
            ]
        ),
    ],
    targets: [
        .target(
            name: "Protobuf",
            path: "objectivec",
            exclude: [
                "Tests",
                "DevTools",
                "BUILD",
                "README.md",
                "generate_well_known_types.sh",
                "generate_spm_include.sh",
                "GPBProtocolBuffers.m",
            ],
            cSettings: [.unsafeFlags(["-fno-objc-arc"])]
        ),
        .target(
            name: "Protobuf+JSONFormat",
            dependencies: ["Protobuf"],
            path: "objectivec+jsonformat",
            publicHeadersPath: ""
        ),
    ]
)
