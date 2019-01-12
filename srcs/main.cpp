/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:15:18 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 10:20:07 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <stdlib.h>
int main(void) {
    WINDOW *boite = NULL;
    std::string *msg= "Texte au centre";
    int taille= size(msg);
    
    initscr();
    while(1) {
        clear();    // Efface la fenêtre (donc l'ancien message)
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);
        refresh();
        if(getch() != 410)
            break;
    }
    
    endwin();
    
    free(boite);
    
    return 0;
}