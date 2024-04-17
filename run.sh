#!/bin/bash

make

./output

rm game.o main.o pacman.o shapes.o utils.o ghost.o commons.o pellet.o output

# while getopts ":h" option; do
#    case $option in
#       d) 
#          rm game.o main.o pacman.o shapes.o utils.o output;;
#    esac
# done

