//
//  client.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/07/18.
//
//


#include "session.h"
#include "tag.h"

main()
{
	int soc;
	char hostname[HOSTNAME_LENGTH];
	
	
	printf("input server's hostname: ");
	fgets(hostname, HOSTNAME_LENGTH, stdin);
	chop_newline(hostname, HOSTNAME_LENGTH);
	
	
	if((soc = setup_client(hostname, PORT)) == -1){
		exit(1);
	}
	
	
	session_init(soc, 'x', 10, 10, 'o', 1, 1);
	
	
	session_loop();
}