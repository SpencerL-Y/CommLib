#pragma once
#include <stdio.h>
#include <arpa/inet.h>

#define ETH_P_888F 0x888f

typedef struct ether_header {
	u_char h_dest[6];// destination mac address
	u_char h_source[6];// source mac address
	u_short type;// ethernet type
} ether_header;

typedef struct auth_header {
	u_char version;// version number 
	u_char type;// type 
	u_int serial_num;// serial number 
	u_int timestamp;// time stamp
	u_short length;// length
} auth_header;

typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
} ip_address;

typedef struct {
	// type = 0x01
	auth_header auth_hdr;
	u_char gateway_mac[6];
	int gateway_random_number;
	ip_address gateway_id;
	u_char signature[16];
} GwAnce;

typedef struct {
	// type = 0x10
	auth_header auth_hdr;
	ip_address client_id;
	char client_mac[6];
	int gateway_random_number;
	ip_address gateway_id;
	u_char client_signature[16];
} AcAuthReq_C2G;

typedef struct {
	// type = 0x10
	auth_header auth_hdr;
	ip_address client_id;
	char client_mac[6];
	int gateway_random_number;
	ip_address gateway_id;
	u_char client_signature[16];
	u_char gateway_signature[16];
} AcAuthReq_G2S;

typedef struct {
	// type= 0x11
	auth_header auth_hdr;
	ip_address client_id;
	int authorization;
	ip_address client_ip_and_mask[2];
	ip_address gateway_ip;
	ip_address client_ip;
	char client_prikey[10];
	int random_num_rs;
	ip_address server_id;
	u_char server_signature[16];
} AcAuthAns;

typedef struct {
	// type = 0x20
	auth_header auth_hdr;
	ip_address client_id;
	int random_num_rs;
	ip_address server_id;
	u_char server_signature[16];
} AuthQu;


typedef struct {
	// type = 0x21
	auth_header auth_hdr;
	int random_number_rs;
	ip_address client_id;
	u_char client_signature[16];
}AuthQuAck;


typedef struct {
	//0x30
	int random_number_rs;
	int gateway_random_number;
	ip_address client_id;
	u_char client_signature[16];
}MaintProbeReq;

typedef struct {
	//0x31
	auth_header auth_hdr;
	ip_address client_id;
	int random_number_rs;
	ip_address server_id;
	u_char server_signature[16];
}MaintProbeAns;

typedef struct {
	//0x40
	auth_header auth_hdr;
	ip_address client_id;
	int auth_result;
	int authorization;
	int random_number_rs;
	ip_address server_id;
	u_char server_signature[16];

} AuthChangeNotify;

typedef struct {
	//0x41
	auth_header auth_hdr;
	ip_address client_id;
	ip_address gateway_id;
	u_char gateway_signature[16];
}AuthChangeAns_G2S;

typedef struct {
	//0x41
	auth_header auth_hdr;
	int gateway_random_number;
	int client_id;
	u_char client_signature[16];
}AuthChangeAns_C2G;

typedef struct udp_header {
	u_short sport;          
	u_short dport;          
	u_short len;               
	u_short crc;            
} udp_header;

typedef struct ip_header {
	u_char  ver_ihl;		  
	u_char  tos;			   
	u_short tlen;            
	u_short identification;    
	u_short flags_fo;       
	u_char  ttl;            
	u_char  proto;          
	// 1: ICMP, 6: TCP, 17: UDP
	u_short crc;            
	ip_address  saddr;      
	ip_address  daddr;      
	u_int   op_pad;         
} ip_header;