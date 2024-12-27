## 本项目还没写注释, 可能会存在代码阅读障碍
# 目录

- [寄语](#%E5%AF%84%E8%AF%AD)
- [使用方法](#%E4%BD%BF%E7%94%A8%E6%96%B9%E6%B3%95)
- [题目描述](#%E9%A2%98%E7%9B%AE%E6%8F%8F%E8%BF%B0)
	- [2024软件学院C++课程设计](#2024%E8%BD%AF%E4%BB%B6%E5%AD%A6%E9%99%A2C++%E8%AF%BE%E7%A8%8B%E8%AE%BE%E8%AE%A1)
		- [课程设计目的：](#%E8%AF%BE%E7%A8%8B%E8%AE%BE%E8%AE%A1%E7%9B%AE%E7%9A%84%EF%BC%9A)
		- [课程设计题目：模拟即时通信系统实现](#%E8%AF%BE%E7%A8%8B%E8%AE%BE%E8%AE%A1%E9%A2%98%E7%9B%AE%EF%BC%9A%E6%A8%A1%E6%8B%9F%E5%8D%B3%E6%97%B6%E9%80%9A%E4%BF%A1%E7%B3%BB%E7%BB%9F%E5%AE%9E%E7%8E%B0)
- [Qt的安装与构建套件的选择](#Qt%E7%9A%84%E5%AE%89%E8%A3%85%E4%B8%8E%E6%9E%84%E5%BB%BA%E5%A5%97%E4%BB%B6%E7%9A%84%E9%80%89%E6%8B%A9)



## 寄语

东方欲晓, 莫道君行早. 尽早开始课设的设计总比到最后临时抱佛脚强. 

希望学弟们不到 ***万不得已*** , 不要直接使用此项目的代码作为课设报告

## 使用方法

1. 使用Qt打开此项目的 `cpp_dyh.pro`
2. 随便选一个构建套件, 然后点击 `Configure Project` 按钮 *(推荐使用 `MinGW 11.2.0 64-bit` ,因为ExTNT使用的此套件)*
3. 按下 `Ctrl + B`, 然后按下 `Crtl + R`
4. 恭喜你, 现在项目开始运行了

> 如果你不会安装Qt和构建套件, 请前往 README 的最后看看如何安装Qt

## 题目描述

> 如果题目差不多一致, 请放心使用此项目 *(大概率是祖传项目)*

### 20xx反恐精英学院C++课程设计

#### 课程设计目的：

1. 熟悉利用面向对象的方法以及C++的编程思想来完成系统的设计；
2. 锻炼学生在设计的过程中，建立清晰的类层次，应用继承和多态等面向对象的编程思想；
3. 通过本课程设计，加深对面向对象程序设计课程所学知识的理解，熟练掌握和巩固C++语言的基本知识和语法规范,深刻体会面向对象的编程思想，掌握使用面向对象程序设计语言C++，学会编写结构清晰、风格良好的C++语言程序，从而具备利用计算机编程分析解决综合性实际问题的初步能力。

#### 课程设计题目：模拟即时通信系统实现

1. 基于社交的即时通信是腾*公司的主要业务，先后有QQ、微信、微博等服务，可能还将继续推出微商、微唱、微走、微笑等产品。这些软件既可以独立提供服务，又互相辉映关联。腾*公司希望对各系统进行整合，形成统一的立体社交软件平台。现请完成该平台的设计并实现。要求如下：

	1. 用户基本信息：
		- 号码ID，昵称，出生时间，T龄（号码申请时间）、所在地、好友列表、群列表。
		- 微博与QQ共享ID，微信采用独立ID，但是可以与QQ号码绑定对应。其他微X产品也分为这两种情况。
	2. 好友管理
		1. 实现各功能好友信息的添加、修改、删除、查询的功能。
		2. 可以查询微X之间各自共同好友。如微信可以添加QQ推荐好友。
	3. 群管理
		1. 设定每个微X功能已有1001、1002、1003、1004、1005、1006等群号。
		2. 加入群、退出群、挨T、查询群成员等。
		3. 不同微X之间群的理念不同，比如：QQ群可以申请加入，而微信群则只能推荐加入；QQ群允许设置临时讨论组（子群），微信群则不允许；QQ群有以群主为核心的管理员制度，而微信群仅有群主为特权账号。
	4. 开通管理
		- 用户可以选择自己开通该平台的N个微X服务。
	5. 登录管理
		- 各微X之间只要有一个服务登录，则其它服务简单确认后视为自动登录。
	6. 功能展示要求（main函数）
		1. 设计约定。开通服务情况、群成员信息和好友信息可以预先保存到文件中，在系统启动时将这些信息加载到内存中；
		2. 一个服务登录后，本人开通的其它所有服务均进入开通状态。
		3. 服务之间可以依据本人开通的任意另外一个服务的好友添加好友。
		4. 展示一个服务当前群的特色功能；在群成员数据不受伤害的前提下，动态变换为其他类型群的管理特色。
		5. 实现QQ的点对点的TCP通信的收发功能。(选做）提示：
			1. 需要加载ws2_32.lib静态库，打开头文件winsock.h。
			2. 百度IP地址、端口等概念；
			3. 百度socket编程，关注bind、listen、accept、connect、send、receive等函数用法。
2. 技术层次要求及说明
	1. 基本层次。
		- 完成上述功能要求，所采用技术不限，比如采用纯面向过程思想实现；
	2. 支持对象层次。
		- 正确完成了类的切割，利用对象技术实现。
			1. 容器类主要包括：例如，微X成员管理。
			2. 其它主要类包括：例如，微X信息、群信息、好友信息。
	3. 抽象、封装层次
		- 采用了继承或者组合实现复用，对数据成员提供了必要的接口保护；
			1. 抽象出了基础类，并被其它功能复用；
			2. 如好友维护、群信息维护等操作均应该提供接口形式；
	4. 面向对象层次
		- 支持多态功能，支持依据设计原则的优化。
		- 好友管理、群管理等；
	5. 优化提高层次
		1. 提供简便菜单，以1、2等数字区分几类功能，并允许返回菜单；
		2. I/O操作支持。基本功能中，已有设定信息，在初始化时候可以固化在程序代码中，也可以存放在文件中，每次容器实例化时读入，析构时写回文件中，以实现断电保存。
		3. 可扩展性支持，需要考虑群、好友等与主要服务之间的关系；
		4. 灵活性支持。群的管理模式动态可变；
		5. 程序有必要的注释；(暂时还没写注释, 以后可能会考虑写)
		6. 可以采用UML工具画出简单类图
		7. **为防止不诚信行为，要求类的设计均以独立文件存在，且所有的类名称后面应有自己的姓名缩写，如张三设计的QQ信息类名称：TencentZhS。** (如果直接使用此项目的代码, 记得改成自己名字简写, 把 `*_dyh` 改成自己的简写)
3. 设计步骤(参考)：
	- 在清楚上述系统功能要处理是什么的基础上，考虑用如下方式来设计
	1. 确定所需的类及其相互间的关系。
		1. 要从问题中归纳出一个概念或实体，从这些概念或实体出发建立相应的类。
		2. 尽量使类小而简单，以使其看起来容易理解。
		3. 充分利用封装以增加类的可靠性，以便使用时保证更加可靠。
		4. 通过继承建立类族，以方便使用多态性。
	2. 确定每个类的实现。
		1. 考虑类的对象应该如何构造和析构。
		2. 综合考虑各个类在命名和功能方面有哪些共性。
	3. 细化有关的类，描述他们之间的相互关系，即类关系和对象关系。
	4. 描述本系统的界面，通过分别定义成员的不同属性，为抽象和实现提供分离的接口。
4. 设计工具
	1. 设计工具：建议使用.net 系列中的C++ 编译器，但不局限于此
	2. 不提倡使用MFC和可视化开发技术
5. 设计报告
	- （报告的具体格式附后）

> *(README就不考虑加入报告格式了)*

6. 考核方式
	1. 在设计结束前的最后一天检查程序并接受质疑
	2. 检查程序前须提交设计报告（按提交报告的先后顺序检查程序）
7. 考核标准
	- 参照5个技术层次划分
8. 课程设计后作业（不考核）
	- 引入可视化设计，在本课程设计基础上实现可视化QQ即时通信功能，包括： 多人聊天；聊天记录查询。需要涉及知识如下：
	1. 网络通信编程
	2. 可视化编程
	3. 多线程编程
	4. 数据库编程

## Qt的安装与构建套件的选择

> 如果一直卡在下载, 请考虑挂载清华源, 中科院源, 腾讯源等镜像; 具体步骤请自行百度 *(^-^)* 

1. 打开电脑
2. 打开浏览器
3. 打开链接 [Qt | 软件开发全周期的各阶段工具](https://www.qt.io/zh-cn/)
4. 点击右上角的 `Download. Try.`按钮
5. 点击右侧中上部的 `选择开源版 > `
6. 向下滚动网页找到一个绿色矩形框, 标题为 `Looking for Qt Binaries?`
7. 点击该框下的 `Download the Qt Online Installer`
8. 点击 `Windows x64`
9. 点击 `Qt Online Installer for Windows(x64)`
10. 如果弹出 "可能损害您的设备, 是否保留", 请选择保留 *(Qt没有病毒, 请放心下载)*
11. 点击`打开文件`
12. 如果没有Qt账户, 请点击注册, 如果有请自行输入账号密码
13. 点击 `下一步`
14. 勾选 `我已阅读并同意使用开源Qt的基本条款和条件` 和 `我是个人用户, 我不为任何公司使用Qt`
15. 点击 `下一步`
16. 点击 `下一步`
17. 勾选 `Disable sending pseudontmous usage statistics in Qt Creator`
18. 点击 `下一步`
19. 点击 `浏览`, 选择一个文件夹作为Qt安装目录 *(尽量不要选择C盘作为安装目录)*
20. 点击 `下一步`
21. 点击 `Qt`
22. 点击 `Qt 6.5.3`前的 **横向绿色三角** *(其他版本也许也行, 但ExTNT使用的是此版本)*
23. 点击 `MinGW 11.2.0 64-bit`
24. 点击 `Build Tools` *(此按钮不在Qt目录下, 和Qt属于同一级目录)*
25. 点击 `MinGW 11.2.0 64-bit`
26. 点击 `OpenSSL 3.0.15 Toolkit` *(或许版本不一样, 但肯定是这个东西)*
27. 点击 `Qt Creator` *(此按钮不在Build Tools目录下, 和Build Tools属于同一级目录)*
28. 点击 `Debug Symbols`
29. 点击 `Plugin Development`
30. 点击 `下一步`
31. 勾选 `I have read and agree to the terms contained in the lincese agreements`
32. 点击 `下一步`
33. 后面不用教了, 无脑下一步
