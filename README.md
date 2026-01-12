# Edra-SDK

A GPU SDK for building applications with full access to modern graphics features.

cmake -S . -B build -DEdraSDK_DIR=${path}$/Edra-SDK/build #Dev #install sdk on app

# Artifact

cmake --build build --config debug #debug
cmake --build build #release

# install

cmake --install build --prefix ./EdraSDK --config debug
