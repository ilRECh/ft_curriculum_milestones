.PHONY: up down clean

up:
	mkdir -p /home/d/data
	mkdir -p /home/d/data/mariadb
	mkdir -p /home/d/data/wordpress
	docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env build
	docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up

down:
	docker-compose -f srcs/docker-compose.yml down

clean: down
	docker rmi $(sudo docker images -qa)
	docker volume rm $(sudo docker volume ls -q)
	docker system prune -a --force
