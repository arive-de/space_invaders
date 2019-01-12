/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:14:39 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 15:59:08 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/Enemy.hpp"
#include "../includes/World.hpp"

int main()
{
    Player *player = new Player("John");
    Enemy *enemy[50];
    for (int i = 0; i < 50; i++)
        enemy[i] = new Enemy("Spaceship");
    World *world = new World(*player, enemy);


    return 0;
}