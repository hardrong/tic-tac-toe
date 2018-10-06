#include "game.h"

void game()
{   
	char ret={0};
	char board[ROW][COL] = {0};
	init_board(board,ROW,COL);
	print_board(board,ROW,COL);
	do
	{
		player_move( board, ROW, COL);
		print_board(board,ROW,COL);
	   ret= is_win( board, ROW, COL);
	   if(ret=='Y')
	   {
		   printf("恭喜，郭宇洁是大坏蛋。\n");
		   break;
	   }
	    if(ret=='N')
	   {
		   printf("很遗憾，你输了\n");
		   break;
	   }
		if(ret=='P')
		{
			 printf("你和电脑居然平局了！！！\n");
			 break;
		}
		computer_move(board,ROW,COL);
		printf("电脑走：\n");
		print_board(board,ROW,COL);
		ret= is_win( board, ROW, COL);
		  if(ret=='Y')
	   {
		   printf("恭喜，郭宇洁是大坏蛋。\n");
		   break;
	   }
		   if(ret=='N')
	   {
		   printf("很遗憾，你输了\n");
		   break;
	   }

    }
	while(ret=='G');
  
}
void menu()
{
	printf("_____________________\n");
	printf("|*******************|\n");
	printf("|******1.play*******|\n");
	printf("|******0.exit*******|\n");
	printf("|*******************|\n");
	printf("---------------------\n");
}
int main()
{

	int input = 0;
	srand( (unsigned ) time(NULL));
	do
	{
		menu();
	    printf("请选择：");
		scanf("%d",&input);
         switch(input)
		   {
		   case 1:
			   game();
			  break;
		   case 0:
			   printf("退出游戏");
			    
			   break;
		   default:
			   printf("输入错误，请重新选择:\n");
				   break;
		   }
	}
		   while(input);
	
      return 0;
	
}
