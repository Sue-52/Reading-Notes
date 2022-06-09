---
title: 第一章-了解Web及网络基础
date: 2022-06-07
---

## 第一章-了解 Web 及网络基础

当用户在网页浏览器（Web browser）的地址栏输入 URL 时，页面是如何显示吗？

![image-20220608081704217](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608081704217.png)

根据 Web 浏览器地址栏中指定的 URL，Web浏览器端获取文件资源（resource）等信息，从而显示 Web 页面。

![image-20220608081816015](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608081816015.png)

Web 使用一种名为 HTTP（HyperText Transfer Protocol，超文本传输协议）的协议作为规范，从而完成从客户端到服务端的一系列运作流程。

### 网络基础 TCP/IP

通常使用的网络（包括互联网）是在 TCP/IP 协议族的基础上运作的，而 HTTP 属于它内部的子集。

#### TCP/IP 协议族

![image-20220608082358989](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608082358989.png)

协议中存在各式各样的内容。像这样把互联网关联的协议集合总称为 TCP/IP。

#### TCP/IP 的分层管理

主要分为四层：应用层、传输层、网络层和数据链路层

通过层次划分，如要修改某个地方的设计，只需要修改当前层次的内容即可。

**TCP/IP 系一组各层作用：**

- **应用层：**

  决定了向用户提供应用服务时通信活动。

  TCP/IP 协议族内预存了各类通用的应用服务。比如，**FTP（File Transfer Protocol，文件传输协议）**和 **DNS（Domain Name System.域名系统）**服务就是其中两类。HTTP协议也处于该层。

- **传输层：**

  提供处于网络连接中的两台计算机之间的数据传输。

  在传输层有两个性质不同的协议：**TCP（Transmission Control Protocol，传输控制协议）**和 **UDP（User Data Protocol，用户数据报协议）**。

- **网络层（网络互连层）：**

  处理网络上流动的数据包。数据包是网络传输的最小数据单位。该层规定了通过增氧的路径（传输路线）到达对方计算机，并把数据包传送给对方。

  与对方计算机之间通过多台计算机或网络设备进行传输时，网络层的作用就是在众多选项内选择一条传输路线。

- **链路层（数据链路层，网络接口层）：**

  用来处理连接网络的硬件部分。包括控制操作系统、硬件的设备驱动、NIC（Network Interface Card，网络适配器，即网卡），及光纤等物理可见部分（还包括连接器等一切传输媒介）。硬件上的范畴均在链路层的作用范围之内。

#### TCP/IP 通信传输流
![image-20220608083701814](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608083701814.png)

利用 TCP/IP 协议族进行网络通信时，分通过分层顺序与对方进行通信。发送端从应用层往下走，接收端从链路端往上走。

- 首先，客户端在应用层（HTTP 协议）发送了一个 Web 页面的 HTTP 请求
- 然后，为了传输信息，在传输层（TCP 协议）把应用层收到的数据（HTTP 请求报文）进行分割，并在各个报文上标记序号及端口转发到网络层
- 紧接着，网络层（IP 协议）增加作为通信目的的 MAC 地址后转发到链路层。（网络通信准备完成了）
- 最后，接收端的服务器在链路层接受数据，按照顺序网上发送，一直到应用层。

只用传输到了应用层才能真正接收到客户端发送过来的 HTTP 请求。

![image-20220608084420450](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608084420450.png)

发送端在层与层之间传输数据时，每经过一层时必定会被打上一个该层所属的首部信息。反之，接收端在层与层传输数据时，每经过一层时会把对应的首部消去。

这种把数据信息包装起来的做法称为**封装（encapsulate）**。

### HTTP 密切相关的协议：IP、TCP、DNS

#### 负责传输的 IP 协议

IP（Internet Protocol）网际协议位于网络层。介乎所有网络系统都会使用 IP 协议。

该协议的作用将数据包传送给对方。为了确保传送到对方电脑组需要两个重要条件：**IP地址**和 **MAC地址（Media Access Control Address）**。

IP 地址制定了节点被分配到的地址，MAC 地址是指网卡所属的固定地址。IP 地址可以和 MAC 地址进行配对。IP 地址可变换，但 MAC 地址基本上不会更改。

- **使用 ARP 协议凭借 MAC 地址进行通信**

  IP间的通信依赖于 MAC 地址。基本通过网络设备中转，在中转时，会利用下一站中专设备的 MAC 地址搜索下一个中转目标。

  采用 ARP 协议（Address Resolution Protocol）。ARP 是一种用以解析地址的协议，根据通信方的 IP 地址就可以反查出对应的 MAC 地址。

![image-20220608091155561](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608091155561.png)

中间中转的线路、地址是我们无法进行掌控的。

#### 确保可靠性的 TCP 协议

提供了可靠的字节流服务。

所谓的字节流服务（Byte Stream Service）指的是：为了方便传输，将大块数据分割成以报文段（segment）为单位的数据包进行管理。

所谓可靠的传输服务指的是：能够将数据准确可靠地传送给对方。

一言以蔽之，TCP 协议为了更容易传送大数据才把数据分割，而且 TCP 协议能够确认数据最终是否送达到对方。

- **确保数据送达：**

  三次握手（three-way handshaking）策略。在过程中使用了 TCP的标志（flag）、 SYN（synchronize）和 ACK（acknowledgement）。

  - 发送端首先发送一个带 SYN 标志的数据包给对方。
  - 接收端收到后，回传一个带有 SYN/ACK 标志的数据包以示传达确认信息。
  - 最后，发送端再回传一个带 ACK 标志的数据包，代表“握手”结束。

  ![image-20220608092000402](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608092000402.png)

### 负责域名解析的 DNS 服务

DNS（Domain Name System）服务和 HTTP 协议 都是位于应用层。提供了域名到 IP 地址之间的解析服务。

DNS 协议提供通过域名查找 IP 地址，或逆向从 IP 地址反查域名的服务。

![image-20220608092250545](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608092250545.png)

### 各类协议和 HTTP 协议的关系

![image-20220608092411435](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608092411435.png)
