# biblio
# ======
## by fde-capu

This program takes a file named 'list.txt'
and outputs a file named 'bibli.htm'
in bibliographic ABNT norm.

The file 'list.txt' must be formatted:

// Anything.
double slash at begining of line: comment

**\# <p>$A. $T. <b>$R</b>, $E, $P, $Y. $O: \<$L\>. Acesso: $I. $N.**
sharp at begining begining of line:
template in HTML
(take this as an ABNT sample)

...folowed by:

**A** Author, Names; Separated, This Way; Surname, Then First Name
**T** Title Of The Article
**R** (Revista) Periodic Name
**E** Editors
**P** Position of Article in Periodic
**Y** Periodic Publishing Year or Date
**O** 1 is case it is online
**L** Link
**I** Date of Link Visit
**N** Article Extra Data, as ISSN etc.

(...)
The same above repeated for every entry.
All entries must start with "**A**".
The sequence "**TREPYOLIN**" is not relevant.
It is ok to skip lines.

To Do
-----
- Filename as argument
- Launch default system web browser when completed
- Advanced templates
- Better file(s) structure(s)
- Better alignments
- Option -v (verbose)
- Option -o output-file.htm
- Better sort algorythm
- Auto copy to clipboard
- Comments from anywhere in line
