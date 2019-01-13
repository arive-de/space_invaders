/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:14:39 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 17:44:36 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/Spaceship.hpp"
#include "../includes/Alien.hpp"
#include "../includes/World.hpp"

#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

# define UP 119
# define DOWN 115

void        draw_grid(WINDOW *win, World *world){

    for (int y = 1; y < W_Y-1; y++)
        for (int x = 1; x < W_X-1; x++)
            mvwaddch(win, y, x, world->getCharGrid(y, x));

}

bool duration(std::clock_t *_start)
{
    std::clock_t duration = (std::clock() - *_start);

    if (duration > 60000)
    {
        *_start = std::clock();
        return true;
    }
    return false;
}

int main(void) {

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int keycode;
    int score;

    Player *player = new Player("John");
    Spaceship *spaceships[NB_SPACESHIPS];
    for (int i = 0; i < NB_SPACESHIPS; i++)
        spaceships[i] = new Spaceship();
	Alien *aliens[NB_ALIENS];
    for (int i = 0; i < NB_ALIENS; i++)
        aliens[i] = new Alien();
    World *world = new World(*player, spaceships, aliens);

    WINDOW *win = newwin(40, 150, 0, 0);
    WINDOW *win_end;

    keypad(win, TRUE);
    nodelay(win, TRUE);


    std::clock_t c_start = std::clock();

    std::srand(0);
    while (1)
    {
        if (duration(&c_start)) {
            wclear(win);
            box(win, 0, 0);
            draw_grid(win, world);
            mvwprintw(win, 0, 2, " score: %d ", score++);
			mvwprintw(win, 0, 12, " pv: %d ", player->getHealth());
            if (player->getHealth() <= 0)
            {
                score = 0;
                win_end = subwin(win, 5, 31, W_Y / 2 - 2.5, W_X / 2 - 15.5);
				box(win_end, 0, 0);
                mvwprintw(win, W_Y / 2 - 1, W_X / 2 - 12.5, "GAME OVER, continue ? Y/n");
                wrefresh(win_end);
            }
            world->makeTheRules();
            wrefresh(win);
        }
        if ((keycode = wgetch(win)) == ERR)
            continue;
        else if (keycode == 'y')
        {
			score = 0;
            player->setHealth(5);
			if (win_end != NULL) {
				delwin(win_end);
			}
            delete world;
            for (int i = 0; i < NB_SPACESHIPS; i++)
        		spaceships[i] = new Spaceship();
			Alien *aliens[NB_ALIENS];
    		for (int i = 0; i < NB_ALIENS; i++)
        		aliens[i] = new Alien();
    		world = new World(*player, spaceships, aliens);
           
        }
        else if (keycode == 'n')
        {
            delete player;
            delete world;
            delwin(win);
            endwin();
            return 0;
        }
        else if (keycode == 'w')
               player->decremYPosition();
        else if (keycode == 's')
               player->incremYPosition();
        else if(keycode == ' ')
            player->fireProjectile(player->getYPosition(), player->getXPosition());
    }
    endwin();
    return 0;
}
