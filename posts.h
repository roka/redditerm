#ifndef __POSTS_H__
#define __POSTS_H__

/* 
	title: Cisco: CryptXXX Technical Deep Dive
	kind: t3
	domain: github.com
	subreddit: netsec
	selftext: 
	id: 4y6je5
	author: sam_bwut
	thumbnail: 
	subreddit_id: t5_1rqwi
	permalink: /r/netsec/comments/4y6je5/azurite_a_tool_for_recon_and_enumeration_of_azure/
	name: t3_4y6je5
	url: https://github.com/mwrlabs/Azurite
*/

typedef struct post post;
struct post {
	char *title;
	char *author;
	char *url;
	char *permalink;
	
	post *head;
	post *tail;
}; 

#endif
