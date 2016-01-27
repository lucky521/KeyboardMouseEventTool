# KeyboardMouseEventTool
Tool to listen Windows keyboard&amp;mouse events

系统键盘鼠标事件监听器，输出所有的键盘敲击，鼠标点击/移动。

主要作为系统开发的诊断工具。




### 命令行版本 Console version
### 图形化版本GUI version 
Current Branch, 当前基于 Qt 5.5.1 界面库。

### 子项目：获取特定键的状态 Sub-project: Get key state
Get state of modifier keys


## Features:
###Done

- hook all events from keyboard and mouse.
- Qt GUI version.
- Format log file.

###Todo

- Get Keyboard&Mouse device info.


## Note
- Windows消息的传递是有顺序的，hook钩子队列（hook chain）按顺序处理事件，后添加的hook会排在前面，先处理事件。
- 如果一个hook回调中不调用将消息传递下去，该消息就到此为止不再被其他钩子收到了。

