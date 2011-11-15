
#!/bin/sh
 
 # openbsd 4.9
 # gcc 4.2.1
 # openjdk 1.7.0
  
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
  javac HelloWorld.java
  javah HelloWorld
  gcc -shared libHelloWorld.c -o libHelloWorld.so
  java HelloWorld
