LibXISF
=========

LibXISF is C++ library that can read and write XISF files produced by [PixInsight](https://pixinsight.com/).
It implement [XISF 1.0 specification](https://pixinsight.com/doc/docs/XISF-1.0-spec/XISF-1.0-spec.html).
It is licensed under GPLv3 or later. To compile you will need C++17 compiler.

To compile simply run these commands
```
cmake -B build -S .
cmake --build build --parallel
cmake --install build
```

By default it use bundled libraries. If you wish to use external libraries you will may add
 `-DUSE_BUNDLED_LIBS=Off` to first command. Then you will need *lz4 pkg-config pugixml zlib* installed.
You may also specify `-DBUILD_SHARED_LIBS=Off` if you want build static lib.

On big endian platform image data are expected to be in big endian format. When loading image
they are converted to host format. When saving the file they are converted to little endian during saving.
