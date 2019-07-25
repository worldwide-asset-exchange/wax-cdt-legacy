# WAX-CDT (Contract Development Toolkit)
## Version : wax-1.6.1-1.0.0
WAX-CDT is a toolchain for WebAssembly (WASM) and set of tools to facilitate contract writing for the WAX platform.

### Guided Installation (Building from Scratch)
We are not providing pre-compiled packages (\*). Therefore, you will have to compile the source code and install it with the following instructions:

```sh
$ git clone --recursive https://github.com/worldwide-asset-exchange/wax-cdt.git
$ cd wax-cdt
$ ./build.sh
$ sudo ./install.sh
```

(\*) But we have docker images:
1. CDT docker [images](https://hub.docker.com/r/waxteam/cdt/tags) based on Ubuntu 18.04 with compiled wax-cdt.
2. Development docker [images](https://hub.docker.com/r/waxteam/dev/tags) ready to be used (they include wax-blockchain, wax-cdt and native/wasm C++ compilers). For a usage example, see [this](https://github.com/worldwide-asset-exchange/wax-blockchain/tree/develop/samples/hello-world).

### Installed Tools
---
* eosio-cpp
* eosio-cc
* eosio-ld
* eosio-init
* eosio-abidiff
* eosio-wasm2wast
* eosio-wast2wasm
* eosio-ranlib
* eosio-ar
* eosio-objdump
* eosio-readelf

### Resources
- [Website](https://wax.io)
- [Blog](https://wax.io/blog)
- [Community Telegram Group](https://t.me/wax_io)
- [White Paper](https://wax.io/uploads/WAX_White_Paper.pdf)

### License
[MIT](https://github.com/worldwide-asset-exchange/wax-blockchain/blob/master/LICENSE)

