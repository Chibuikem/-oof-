# Binary & Text File Converter
> This is a small program that converts a given text file into a binary file. The resulting binary file or another binary file can similarly be converted to a text file.

![Build Status][travis-image]

![](header.png)
## File Format

The format of the text file to be converted is specified as follows below:
```sh
FirstName LastName ID_Number GPA
```
The file can have an infinite amount of entries as long as the format is correct.
```FirstName``` and ```LastName``` is a ```String```,
```ID_Number``` is an ```int``` and
```GPA``` is a ```float```

Each entry is separated by either a space or a new line.

An example file is given below:
```sh
John Doe 8317 4.0
Jane Doe 34578 4.0
Harry Potter 100 3.5
```
## Development setup
For a quick and easy setup, with the files located in the same directory, compile the code with the command
```sh
gcc converter.c binaryToText.c secondForm.c textToBinary.c -o converter 
```

### Usage example

To convert a text file ```example.txt``` to a binary. It can be achieved as follows:
```./converter -t example.txt outputFile```

### Flags
As in the example above, ```-t``` is a flag that is specified for the program to run. There are 3 flags that can be used in this program.

```-t``` specifies a text file is being converted ```./converter -t TextFile BinaryFile```

```-b``` specifies a binary file is being converted ```./converter -b BinaryFile TextFile```

```-s``` takes in a binary file, finds the longest full name and prints it ```./converter -s BinaryFile```

## Release History
* 0.0.0
    * Fully Functional Release
* 0.0.1
    * Work in progress (could use some revision)

## Meta

Chibuikem Ajulu-Okeke – cajuluokeke@gmail.com

Distributed under the XYZ license. See ``LICENSE`` for more information.

[https://github.com/Chibuikem/-oof-/](https://github.com/Chibuikem/)


<!-- Markdown link & img dfn's -->
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
