# AWK script
# provides a starting point for developing custom parameter scanning scripts
 
BEGIN {
modfile = "test.mod";
datfile = "test.dat";
system("rm --force " modfile);        # Linux remove call
printf ("Writing model file\n");
printf ("# model file\n") > modfile;
printf ("param iter;\n") > modfile;
printf ("solve;\n") > modfile;
printf ("display iter;\n") > modfile;
printf ("end;\n") > modfile;
close(modfile);
for (i = 1; i <= 5; i++) {
  system("rm --force " datfile);      # Linux remove call
  printf("\n\nIteration %i\n", i);
  printf ("Writing data file\n");
  printf("# data file %i\n", i) > datfile;
  printf("data;\n") > datfile;
  printf("param iter := %i;\n", i) > datfile;
  printf("end;\n") > datfile;
  close(datfile);
  system("glpsol --model " modfile " --data " datfile);
  }
exit;
}
