/*
 * io_port_driver.h
 *
 *  Created on: Mar 27, 2016
 *      Author: developer
 */

#ifndef IO_PORT_DRIVER_H_
#define IO_PORT_DRIVER_H_

void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);

#endif /* IO_PORT_DRIVER_H_ */
