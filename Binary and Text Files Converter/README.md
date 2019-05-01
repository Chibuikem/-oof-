# Binary & Text File Converter
> This is a small program that converts a given text file into a binary file. The resulting binary file or another binary file can similarly be converted to a text file.

[![NPM Version][npm-image]][npm-url]
[![Build Status][travis-image]][travis-url]
[![Downloads Stats][npm-downloads]][npm-url]

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

```-t``` specifies a Text File is being converted ```./converter -t TextFile BinaryFile```

```-b``` specifies a Binary File is being converted ```./converter -b BinaryFile TextFile```

```-s``` takes in a Binary File, finds the Longest Full Name and Prints it ```./converter -s BinaryFile```

## Release History

* 0.2.1
    * CHANGE: Update docs (module code remains unchanged)
* 0.2.0
    * CHANGE: Remove `setDefaultXYZ()`
    * ADD: Add `init()`
* 0.1.1
    * FIX: Crash when calling `baz()` (Thanks @GenerousContributorName!)
* 0.1.0
    * The first proper release
    * CHANGE: Rename `foo()` to `bar()`
* 0.0.1
    * Work in progress

## Meta

Your Name – [@YourTwitter](https://twitter.com/dbader_org) – YourEmail@example.com

Distributed under the XYZ license. See ``LICENSE`` for more information.

[https://github.com/yourname/github-link](https://github.com/dbader/)

## Contributing

1. Fork it (<https://github.com/yourname/yourproject/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki
