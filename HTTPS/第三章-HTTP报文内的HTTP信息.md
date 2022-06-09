---
title: HTTP报文内的HTTP信息
date: 2022-06-09
---

## 第三章-HTTP报文内的HTTP信息

### HTTP 报文

用于 HTTP 协议交互的信息被称之为 HTTP 报文。

> 请求端（客户端）的HTTP 报文叫做请求报文，响应端（服务器端）的叫做响应报文。

主体分为两部分：

- 报文首部
- 报文主体

![image-20220609083858457](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609083858457.png)

### 请求报文及响应报文的结构

![image-20220609083947714](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609083947714.png)

![image-20220609084012472](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609084012472.png)

- **请求行：**

  包含用于请求的方法，请求 URI 和 HTTP 版本

- **状态行：**

  包含了响应结果状态码，原因短语和 HTTP 版本

- **首部字段：**

  包含了请求和响应的各种各样条件和属性

  一般分为：通用首部、请求首部、响应首部、实体首部

- **其他：**

  可能包含 HTTP 的 RFC 里未定义的首部（Cookie 等）。

### 编码提升传输效率

#### 报文主体和实体主体的差异

- 报文（Message）

  是 HTTP 通信中的基本单位，由 8 位组字节流（octet sequence，octet为 8 bytes）组成，通过 HTTP 通信传输。

- 实体（entity）

  作为请求或响应的有效载荷数据（补充项）被传输，其内容由实体首部和实体主体组成。

HTTP 报文的主体用于传输请求或响应的实体主体。

#### 压缩传输的内容编码

HTTP 协议中有一种被称为内容编码的功能是为了压缩数据的。

内容编码指明应用在实体内容上的编码格式，并保持实体信息原样压缩。内容编码后的实体由客户端接收并负责解码。

![image-20220609090528171](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609090528171.png)

- gzip（GNU zip）
- compress（UNIX 系统的标准压缩）
- deflate（zlib）
- identity（不进行编码）

#### 分割发送的分块传输编码

在 HTTP 通信过程中，请求的编码实体资源尚未全部传输完成之前，浏览器无法显示请求页面。在传输大容量数据时，通过把数据分割成多块，能够让浏览器逐步显示页面。

这种把实体主体分块的功能称为分块传输编码（Chunked Transfer Coding）。

![image-20220609090918947](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609090918947.png)

### 发送多种数据的多部分对象集合

发送邮件采用了 MIME（Multipurpose Internet Mail Extensions，多用途因特网邮件扩展）机制处理邮件的文本、图片、视频不同类型的数据。

![image-20220609091148726](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609091148726.png)

多部分对象集合包含的对象如下：

- multipart/form-data

  在 Web 表单文件上产时使用

- multipart/byteranges

  状态码 206（Partial Content，部分内容）响应报文包含了多个范围的内容时使用。

### 获取部分内容的范围请求

以前，用户不能使用现在这种高速的带宽访问互联网，当时，下载一个尺寸稍大的图片或文件就已经很吃力了。如果下载过程中遇到网络中断的情况，那就必须重头开始。为了解决上述问题，需要一种可恢复的机制。所谓恢复是指能从之前下载中断处恢复下载。

要实现该功能需要指定下载的实体范围。像这样，指定范围发送的请求叫做范围请求（Range Request）。

![image-20220609091554270](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609091554270.png)

- 5001 ~ 10000 字节

  ~~~bash
  Range: bytes=5001-10000
  ~~~

- 从 5001 字节之后全部的

  ~~~bash
  Range: bytes=5001-
  ~~~

- 从一开始到 3000 字节和 5000~7000 字节的多重范围

  ~~~bash
  Range: bytes=-3000, 5000-7000
  ~~~

针对范围请求，响应会返回状态码为 206 Partial Content 的响应报文。另外，对于多重范围的范围请求，响应会在首部字段 Content-Type标明 multipart/byteranges 后返回响应报文。

如果服务器端无法响应范围请求，则会返回状态码 200 OK 和完整的实体内容。

### 内容协商返回最合适内容

当浏览器的默认语言为英语或中文，访问相同 URI 的 Web 页面时，则会显示对应的英语版或中文版的 Web 页面。这样的机制称为内容协商（Content Negotiation）。

![image-20220609091821182](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609091821182.png)

三种类型：

- 服务器驱动协商（Server-driven Negotiation）

  由服务器端进行内容协商。以请求的首部字段为参考，在服务器端自动处理。但对用户来说，以浏览器发送的信息作为判定的依据，并不一定能筛选出最优内容。

- 客户端驱动协商（Agent-driven Negotiation）

  由客户端进行内容协商的方式。用户从浏览器显示的可选项列表中手动选择。还可以利用 JavaScript 脚本在 Web 页面上自动进行上述选择。比如按 OS 的类型或浏览器类型，自行切换成 PC 版页面或手机版页面。

- 透明协商（Transparent Negotiation）

  是服务器驱动和客户端驱动的结合体，是由服务器端和客户端各自进行内容协商的一种方法。











