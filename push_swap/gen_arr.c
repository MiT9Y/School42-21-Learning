//ARG=`./gen_arr 500`; echo $ARG; PS_=`./push_swap $ARG`; echo $PS_; PS=`echo $PS_ | sed 's/ /\\\n/g'`; echo -e $PS | wc -l; echo -e $PS | ./checker $ARG

#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#include <stdio.h>
#include <stdlib.h>


struct timespec get_time()
{
	struct timespec ts;

	#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts.tv_sec = mts.tv_sec;
	ts.tv_nsec = mts.tv_nsec;

	#else
	clock_gettime(CLOCK_REALTIME, &ts);
	#endif
	return (ts);
}

char no_check_el(unsigned int el, unsigned int *arr, unsigned int len)
{
	unsigned int i = -1;
	while (++i < len)
		if (arr[i] == el)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	unsigned int	nmb;
	unsigned int	el;
	unsigned int	*arr;
	unsigned int	len = 0;

	if (argc == 2)
	{
		nmb = atoi(argv[1]);
		arr = malloc(sizeof(*arr) * nmb);
		if (!arr)
			exit(1);
		while (len < nmb)
		{			
			el = ((get_time()).tv_nsec / 1000) % nmb;
			while (no_check_el(el, arr, len))
				el = ((get_time()).tv_nsec / 1000) % nmb;
			arr[len] = el;
			len++;
		}
		el = -1;
		if (nmb != 0)
		{
			while(++el < (nmb - 1))
				printf("%u ", arr[el]);
			printf("%u", arr[el]);
		}
	}
	printf("\n");
}