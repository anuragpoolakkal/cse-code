To run C programs:

```
gcc filename.c
./a.out
```

To run lex programs:

```
lex filename.l
gcc lex.yy.c
./a.out
```

To run yacc programs:

```
yacc -d filename.y
lex filename.l
gcc lex.yy.c y.tab.c
./a.out
```
