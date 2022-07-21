INCEPTION_PATH = C:\Inception
VOLUMES_PATH=$(INCEPTION_PATH)/srcs/requirements/volumes

all: down
	@echo "Check and Copy shared files..."
	@mkdir -p $(VOLUMES_PATH)/mariadb $(VOLUMES_PATH)/wordpress
	@cp -n -R $(INCEPTION_PATH)/srcs/requirements/tools/wordpress $(VOLUMES_PATH)
	@echo "Check and Copy finished."
	docker-compose -f $(INCEPTION_PATH)/srcs/docker-compose.yml up --build -d

stop:
	docker-compose -f $(INCEPTION_PATH)/srcs/docker-compose.yml down

down: stop
	@docker rmi -f gateway
	@docker rmi -f mariadb
	@docker rmi -f wordpress
	@docker rmi -f nginx

clean: down
	docker volume rm -f wordpress mariadb
	@if [ $(shell docker network ls | grep inception_network | wc -l) = "1" ]; then docker network rm inception_network; fi
	@rm -f -R $(VOLUMES_PATH)/mariadb
	@rm -f -R $(VOLUMES_PATH)/wordpress

ps:
	docker-compose -f $(INCEPTION_PATH)/srcs/docker-compose.yml ps

logs:
	docker-compose -f $(INCEPTION_PATH)/srcs/docker-compose.yml logs

.PHONY: all stop down clean ps logs
