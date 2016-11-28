##
## Makefile for  in /home/veyrie_f/rendu/CPE_2014_corewar
## 
## Made by fernand veyrier
## Login   <veyrie_f@epitech.net>
## 
## Started on  Sun Apr 12 23:33:30 2015 fernand veyrier
## Last update Thu Apr 16 13:03:27 2015 fernand veyrier
##

all:
	cd ./asm && make
	cd ./corewar && make

clean:
	cd ./asm && make clean
	cd ./corewar && make clean

fclean:
	cd ./asm && make fclean
	cd ./corewar && make fclean

re: fclean all
