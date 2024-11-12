/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <string.h>
#include "esp_log.h"

QueueHandle_t queue_handle = NULL;

typedef struct 
{
    /* data */
    int value;
} queue_t;

void task_rec(void *p)
{
    //从队列里边接收数据并打印
    queue_t queue;
    while (1)
    {
        if (pdTRUE == xQueueReceive(queue_handle, &queue.value, 100))
        {
            ESP_LOGI("queue"," receive value:%d", queue.value);
        }
    }
    
}

void task_sen(void *p)
{
    queue_t queue;
    memset(&queue.value, 0, sizeof(int));
    while(1)
    {
        xQueueSend(queue_handle, &queue.value, 100);
        vTaskDelay(pdMS_TO_TICKS(1000));
        queue.value++;
    }
}

void app_main(void)
{
    queue_handle =  xQueueCreate(10, sizeof(queue_t));
    xTaskCreatePinnedToCore(task_rec, "task_receive", 2048, NULL, 3, NULL, 1);
    xTaskCreatePinnedToCore(task_sen, "task_send", 2048, NULL, 3, NULL, 1);
}
