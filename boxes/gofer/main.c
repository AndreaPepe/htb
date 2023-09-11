void main(void)

{
  __uid_t _Var1;
  int iVar2;
  undefined4 local_1c;
  void *local_18;
  void *local_10;
  
  local_1c = 0;
  local_10 = (void *)0x0;
  local_18 = (void *)0x0;
  do {
    puts(
        "========================================\n1) Create an user and choose an username\n2) Show  user information\n3) Delete an user\n4) Write a note\n5) Show a note\n6) Save a note (not y et implemented)\n7) Delete a note\n8) Backup notes\n9) Quit\n=============================== =========\n\n"
        );
    printf("Your choice: ");
    __isoc99_scanf(&DAT_0010212b,&local_1c);
    puts("");
    switch(local_1c) {
    default:
                    /* WARNING: Subroutine does not return */
      exit(0);
    case 1:
      local_10 = malloc(0x28);
      if (local_10 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(local_10,0,0x18);
      memset((void *)((long)local_10 + 0x18),0,0x10);
      _Var1 = getuid();
      if (_Var1 == 0) {
        *(undefined4 *)((long)local_10 + 0x18) = 0x696d6461;
        *(undefined *)((long)local_10 + 0x1c) = 0x6e;
      }
      else {
        *(undefined4 *)((long)local_10 + 0x18) = 0x72657375;
      }
      printf("Choose an username: ");
      __isoc99_scanf(&DAT_00102144,local_10);
      puts("");
      break;
    case 2:
      if (local_10 == (void *)0x0) {
        puts("First create an user!\n");
      }
      else {
        printf("\nUsername: %s\n",local_10);
        printf("Role: %s\n\n",(long)local_10 + 0x18);
      }
      break;
    case 3:
      if (local_10 != (void *)0x0) {
        free(local_10);
      }
      break;
    case 4:
      local_18 = malloc(0x28);
      memset(local_18,0,0x28);
      if (local_18 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      puts("Write your note:");
      __isoc99_scanf(&DAT_0010218b,local_18);
      break;
    case 5:
      printf("Note: %s\n\n",local_18);
      break;
    case 6:
      puts("Coming soon!\n");
      break;
    case 7:
      if (local_18 != (void *)0x0) {
        free(local_18);
        local_18 = (void *)0x0;
      }
      break;
    case 8:
      if (local_10 == (void *)0x0) {
        puts("First create an user!\n");
      }
      else {
        iVar2 = strcmp((char *)((long)local_10 + 0x18),"admin");
        if (iVar2 == 0) {
          puts("Access granted!");
          setuid(0);
          setgid(0);
          system("tar -czvf /root/backups/backup_notes.tar.gz /opt/notes");
        }
        else {
          puts("Access denied: you don\'t have the admin role!\n");
        }
      }
    }
  } while( true );
}
