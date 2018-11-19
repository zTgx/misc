       static void
       usage(char *pname)
       {
           fprintf(stderr, "Usage: %s [options] program [arg...]\n", pname);
           fprintf(stderr, "Options can be:\n");
           fprintf(stderr, "    -i   unshare IPC namespace\n");
           fprintf(stderr, "    -m   unshare mount namespace\n");
           fprintf(stderr, "    -n   unshare network namespace\n");
           fprintf(stderr, "    -p   unshare PID namespace\n");
           fprintf(stderr, "    -u   unshare UTS namespace\n");
           fprintf(stderr, "    -U   unshare user namespace\n");
           exit(EXIT_FAILURE);
       }
