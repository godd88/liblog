all:
	gcc -g liblog_config.c liblog.c main.c mod_1.c mod_2.c

clean:
	rm a.out *log
