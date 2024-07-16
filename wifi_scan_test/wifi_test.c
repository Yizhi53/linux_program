#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>


#define wifi_test 1
int file_wc(const char*);

#ifdef wifi_test
int main(int argc, char *argv[])
{
	struct timeval start, end;
    
	printf("test start\n");
	
	
	system("hostapd_cli disable");
	sleep(1);
	
	system("killall -15 hostapd");
	sleep(1);
	system("wpa_supplicant –Dnl80211 -iwlan0 -c /tmp/sp/system/etc/wifimanager/wpa_0_8.conf -B");
	sleep(1);
	gettimeofday( &start, NULL );
	system("wpa_cli -i wlan0 scan &> /tmp/wifi_scan_start.txt");
	//printf("scan start\n");
	//sleep(1);
	
	
	do{
		
		system("wpa_cli -i wlan0 scan_result &> /tmp/wifi_scan_result.txt;");
		sleep(1);
		printf("Line : %d\n", file_wc("/tmp/wifi_scan_result.txt"));
		
	}while(!(file_wc("/tmp/wifi_scan_result.txt") > 2));
	gettimeofday( &end, NULL );
	double timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
	//system("wpa_cli -i wlan0 scan_result &> /tmp/wifi_scan_result.txt;");
	//system("wpa_cli -i wlan0 scan_result");
	//sleep(2);
	system("killall -15 wpa_supplicant");
	sleep(1);
	system("/usr/local/bin/hostapd /media/flash/nvm/softap.conf -B");
	
	
	printf("wifi_scan執行總時間：%f s\n", timeuse*pow(10,-6));
	
	return 0;
}
#else
	int main(int argc, char *argv[])
	{
		printf("Line : %d\n", file_wc("/tmp/wifi_scan_result.txt"));
		
		return 0;
	}
	
#endif

int file_wc(const char* filename)
{
	int fd;
	register int linect = 0;
	char buf[1024];
	int len;
	char *p = NULL;
	

		if((fd = fopen(filename, "r")) == NULL)
		{
			fprintf(stderr, "open %s\n", strerror(errno));
			return -1;
		}
		
		while(fgets(buf, 1024, fd)!= NULL){
			if(buf[strlen(buf)-1] == '\n')
				linect++;
		}
			
	
	return linect;
}
