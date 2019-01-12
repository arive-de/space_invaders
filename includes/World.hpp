/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:10:50 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:49:57 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

#include <string>

#define W_Y 300
#define W_X 400

class World {
    public :
        World();
        ~World();
        // void            getAgentPosition(Player& player);
        // void            getAgentPosition(Enemy& enemy);
        // void            getAgentPosition(Mesh& mesh);
    protected:
        int             **_grid;
        int             playerY;
    private:
};
#endif