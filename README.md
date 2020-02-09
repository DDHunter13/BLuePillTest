# BLuePillTest

## IDE
Atollic TRUE Studio - кроссплатформенная IDE, хорошо с ней знаком, присутствует работа с ST_Link, отладчик.
Генерация стартовых настроек системы тактирования и периферии - CubeMX. Экономит время, подключая библиотеки. Может генерировать проект под несколько IDE.

## RTOS - FreeRTOS

## Модульность
Для контроля светодиода и АЦП написаны отдельные модули, функции которых вызываются задачами системы.

Модуль контроля светодиода умеет менять состояние светодиода и быстро им мигать. Другие модули не знают ни о текущем момтоянии светодиода, ни о способах управления, лишь вызывают функции этого модуля. 

Модуль контроля АЦП измеряет напряжение и температуру, преобразуя полученные с АЦП числа непосредственно в напряжение и температуру. Остальные модули при необходимости вызывают функции данного модуля и работают с полученными значениями.

Каждая задача RTOS'а также является отдельным модулем.

## Задачи системы
1. Индикация работы
Меняет состояние светодиода раз в секунду.
1. Измерения напряжения
Имеет счетчик, в котором накапливает время ожидания запроса на измерение напряжения. Если есть запрос или прошла минута, то производит измерение, выставляя флаг и результат измерения. Счетчик обнуляется при каждом измерении.
1. Измерения температуры
Аналогично имеет счетчик, по которому каждые 2,5 минуты происходит измерение температуры, выствление флага и результата измерения.
1. Работа с UART
Содержит цикл проверки пришедших по UART данных и соответствие этих данных команде запроса ("adc"). Также проверяет флаг наличия данных для отправки и отправляет их, если необходимо. Формат - "temp: %f" или "adc: %f".

## IPC
Связь между задачами (для индикации пришедшего запроса или отправки полученных данных) обеспечивается посредством минимального количества глобальных переменных. По-хорошему FreeRTOS имеет нативные системные очереди, но они кушают память, которой у данной платформы и так мало, поэтому экономия. 

Всего 4 переменных для обеспечения связи:
1. Флаг пришедшего запроса для АЦП
1. Флаг сделанного измерения. Один для напряжения и температуры. Различия в логике работы с этим флагом
1. Последнее измеренное напряжение
1. Последняя измеренная температура

## Адаптивность
По возможности все константы вынесены в одно место для легкой замены настроек по периоду измерений. Аналогично вынесен порт и пин светодиода, так как эти значения используются в модуле контроля светодиода. Значения каналов для АЦП генерировались CubeMXом и могут быть аналогично перегенерированы им же, например.

## Расширяемость
Добавить новые задачи в RTOS для других индикаций, подсчетов, контроля периферии - легко (памяти бы только хватило). Использовать уже готовые модули работы с периферией с новых задачах - тоже. 

При необходимости ввода в систему более высокоприоритетных задач или требовательных к быстродействию - в контроллере остались свободны все 4 таймера, а также установлена далеко не самая низкая частота работы (при желании ее можно поднять через PLL, код проекта никак не поменяется, потому что все расчеты временных задержек отталкиваются от установленной частоты и обновятся сами).
