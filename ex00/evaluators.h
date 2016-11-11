/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:39:43 by icuz              #+#    #+#             */
/*   Updated: 2016/11/10 21:49:09 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATORS_H
# define EVALUATORS_H

int	eval_expr(char *expr);
int	parse_summands(char **expr);
int parse_factor(char **expr);
int	parse_atom(char **expr);
#endif
