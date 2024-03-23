windres [option(s)] [input-file] [output-file]
 The options are:
  -i --input=<file>            Name input file       
  -o --output=<file>           Name output file      
  -J --input-format=<format>   Specify input format 
  -O --output-format=<format>  Specify output format
  -F --target=<target>         Specify COFF target
     --preprocessor=<program>  Program to use to preprocess rc file
     --preprocessor-arg=<arg>  Additional preprocessor argument
  -I --include-dir=<dir>       Include directory when preprocessing rc file
  -D --define <sym>[=<val>]    Define SYM when preprocessing rc file
  -U --undefine <sym>          Undefine SYM when preprocessing rc file
  -v --verbose                 Verbose - tells you what it's doing
  -c --codepage=<codepage>     Specify default codepage
  -l --language=<val>          Set language when reading rc file
     --use-temp-file           Use a temporary file instead of popen to read
                               the preprocessor output
     --no-use-temp-file        Use popen (default)
  -r                           Ignored for compatibility with rc
  @<file>                      Read options from <file>
  -h --help                    Print this help message
  -V --version                 Print version information
FORMAT is one of rc, res, or coff, and is deduced from the file name
extension if not specified.  A single file name is an input file.
No input-file is stdin, default rc.  No output-file is stdout, default rc.
windres: supported targets: pe-x86-64 pei-x86-64 pe-bigobj-x86-64 elf64-x86-64 pe-i386 pei-i386 elf32-i386 elf32-iamcu pdb elf64-little elf64-big elf32-little elf32-big srec symbolsrec verilog tekhex binary ihex plugin