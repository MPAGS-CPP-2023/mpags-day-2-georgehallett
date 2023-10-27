# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

## Authors
Thomas Latham, Ben Morgan, Mark Slater, Matt Williams, Luke Kreczko and George Hallett (C++ Legend)

## Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 8 or better, Clang 8 or better are recommended) on a UNIX operating
system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

Supply input file, output file, key, encryption/decryption option. Key is set to 5 by default.

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are output after CTRL-D.

To run type ./mpags-cipher -i ... -o ... -k ...

For help use ./mpags-cipher --help.

## Source code layout
```
.
├── LICENSE             License file, in our case MIT
├── mpags-cipher.cpp    Main program C++ source file
└── README.md           This file, describes the project
```

## Copying
`mpags-cipher` is licensed under the terms of the MIT License.
Please see the file [`LICENSE`](LICENSE) for full details.