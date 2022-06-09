---
title: 第二章-简单的HTTP协议
date: 2022-06-08
---

## 简单的 HTTP 协议

### HTTP 协议用于客户端和服务器端之间的通信

请求访问文本或图像等资源的一端称为客户端，而提供资源响应的一端称为服务器端。

![image-20220608103229064](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608103229064.png)

在两台计算机之间使用 HTTP 协议通信时，在一条通信线路上必定有一端是客户端，另一端则是服务器端。

### 通过请求和响应的交换达成通信

![image-20220608103340667](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608103340667.png)

HTTP 协议规定，请求从客户端发送，最后服务器端响应请求并返回。

![image-20220608103515085](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608103515085.png)

客户端发送给某个 HTTP 服务器端的请求报文中的内容：

~~~bash
GET /index.htm HTTP/1.1
Host: hackr.jp
~~~

起始行开头为：GET，表示请求访问服务器的类型，称为方法（method）。

随后的字符串 `/inde.htm` 制定了请求访问的**资源对象**，也叫请求 URI（request-URI）。

最后的 `HTTP/1.1` ，即 HTTP 的版本号。

> 综合结果：
>
> ​	请求报文是由请求方法、请求 URI、协议版本、可选首部字段和内容实体构成。

![image-20220608104112340](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608104112340.png)

接收到请求的服务器，将请求内容处理结果以响应的形式返回。

![image-20220608104257161](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608104257161.png)

- 起始行开头的 `HTTP/1.1` 表示服务器对应的 HTTP 版本。
- `200 OK` 表示请求的处理结果的状态码（status code）和原因短语（reason-phrase）。
- `Date: Tue, 10 Jul 2012 06:50:15 GMT` 代表创建响应的日期时间，是首部字段（header field）内的一个属性。
- 接着以一空行分隔，之后的内容称为资源实体的主体（entity body）。

![image-20220608104858655](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608104858655.png)

### HTTP 是不保存状态的协议

HTTP 是一种不保存状态，即无状态（stateless）协议。对于自身不对请求和响应之间通信状态进行保存。

![image-20220608105432811](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608105432811.png)

使用 HTTP 协议，每当有新的请求发送时，就会有对应的新响应产生。协议本身并不保留之前一切的请求或响应报文的信息。这是为了更快地处理大量事务，确保协议的可伸缩性，而特意把 HTTP 协议设计成如此简单的。

为了实现期望的保持状态功能，引入了 Cookie 技术。

### 请求 URI 定位资源

HTTP 使用 URI 定位互联网上的资源。

![image-20220608105821957](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608105821957.png)

当客户端请求访问资源而发送请求时，URI 需要将作为请求报文中的请求 URI 包含在内。

![image-20220608111746618](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608111746618.png)

除此之外，如果不是访问特定资源而是对服务器本身发起请求，可以用一个 * 来代替请求 URI。下面这个例子是查询 HTTP 服务器端支持的 HTTP 方法种类：

![image-20220608111811770](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608111811770.png)

### 告诉服务器意图的 HTTP 方法

#### GET：获取资源

用来请求i访问已被 URI 识别的资源。指定的资源经服务器端解析后返回响应内容。

![image-20220608112031662](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112031662.png)

#### POST：传输实体主体

用来传输数据的主体。

GET方法也可以传输实体，但是有相应的限制，通常使用 POST 方法。

![image-20220608112219410](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112219410.png)

![image-20220608112232548](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112232548.png)

#### PUT：传输文件

PUT 方法用来传输文件。就像 FTP 协议的文件上传一样，要求在请求报文的主体中包含文件内容，然后保存到请求 URI 指定的位置。

但是，鉴于 HTTP/1.1 的 PUT 方法自身不带验证机制，任何人都可以上传文件 , 存在安全性问题，因此一般的 Web 网站不使用该方法。若配合 Web 应用程序的验证机制，或架构设计采用 REST（REpresentational State Transfer，表征状态转移）标准的同类 Web 网站，就可能会开放使用 PUT 方法。

![image-20220608112353744](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112353744.png)

#### HEAD：获取报文首部

类似于 GET 方法，只是不反悔报文主体部分，用于确认 URI 的有效性及资源更新的日期时间等。

![image-20220608112503599](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112503599.png)

#### DELETE：删除文件

该方法用于删除文件或数据，是 PUT 相反的方法。DELETE 方法按请求 URI 删除指定的资源。

但是，HTTP/1.1 的 DELETE 方法本身和 PUT 方法一样不带验证机制，所以一般的 Web 网站也不使用 DELETE 方法。当配合 Web 应用程序的验证机制，或遵守 REST 标准时还是有可能会开放使用的。

![image-20220608112638008](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112638008.png)

![image-20220608112648180](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112648180.png)

#### OPTIONS：询问支持的方法

用来查询针对请求 URI 指定的资源支持的方法。

![image-20220608112750407](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608112750407.png)

#### TRACE：追踪路径

TRACE 方法是让 Web 服务器端将之前的请求通信环回给客户端的方法。

发送请求时，在 Max-Forwards 首部字段中填入数值，每经过一个服务器端就将该数字减 1，当数值刚好减到 0 时，就停止继续传输，最后接收到请求的服务器端则返回状态码 200 OK 的响应。

客户端通过 TRACE 方法可以查询发送出去的请求是怎样被加工修改 / 篡改的。这是因为，请求想要连接到源目标服务器可能会通过代理中转，TRACE 方法就是用来确认连接过程中发生的一系列操作。

但是，TRACE 方法本来就不怎么常用，再加上它容易引发 XST（Cross-Site Tracing，跨站追踪）攻击，通常就更不会用到了。

![image-20220608113127340](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608113127340.png)

#### CONNECT：要求用隧道协议连接代理

CONNECT 方法要求在与代理服务器通信时建立隧道，实现用隧道协议进行 TCP 通信。主要使用 SSL（Secure Sockets Layer，安全套接层）和 TLS（Transport Layer Security，传输层安全）协议把通信内容加密后经网络隧道传输。

~~~js
CONNECT 代理服务器名:端口号 HTTP版本
~~~

![image-20220608113212089](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608113212089.png)

### 使用方法下达命令

向请求 URI 指定的资源发送请求报文时，采用成为方法的命令。

![image-20220608113350043](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608113350043.png)

![image-20220608113418112](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220608113418112.png)

### 持久连接节省通信量

![image-20220609081411435](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609081411435.png)

每次进行 HTTP 通信都需要断开 TCP 链接一次。随之而来的就是 HTML 文档对数据的开销问题。

![image-20220609081538527](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609081538527.png)

#### 持久连接

持久化连接（HTTP Persistent Connections，也成为：HTTP keep-alive、HTTP connection reuse），其特点就是只要任意一端没有明确的断开连接则会一直保持 TCP 连接状态。

![image-20220609081756154](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609081756154.png)

减少了重复建立的 TCP 连接和断开造成的开销，减轻服务器压力。

并且页面可以更快的进行加载。

>  在 HTTP/1.1 中，所有的连接默认都是持久连接，但在 HTTP/1.0 内并未标准化。

#### 管线化

持久连接使得多数请求以管线化（pipelining）方式发送成为可能。从前发送请求后需等待并收到响应，才能发送下一个请求。管线化技术出现后，不用等待响应亦可直接发送下一个请求。

![image-20220609082554700](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609082554700.png)

### 使用 Cookie 的状态管理

![image-20220609082917566](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609082917566.png)

Cookie 技术通过在请求和响应报文中写入 Cookie 信息来控制客户端的状态。

Cookie 会根据从服务器端发送的响应报文内的一个叫做 Set-Cookie的首部字段信息，通知客户端保存 Cookie。当下次客户端再往该服务器发送请求时，客户端会自动在请求报文中加入 Cookie 值后发送出去。

![image-20220609083311810](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609083311810.png)

![image-20220609083327017](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609083327017.png)

![image-20220609083337516](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609083337516.png)
