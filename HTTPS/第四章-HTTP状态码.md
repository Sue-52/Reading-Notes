---
title: HTTP 状态码
date: 2022-06-09
---

## 第四章-HTTP状态码

### 状态码告知服务器返回请求结果

![image-20220609093057745](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609093057745.png)

**状态码分类：**

![image-20220609093130056](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609093130056.png)

只要遵守状态码类别的定义，即使改变 RFC2616 中定义的状态码或服务器端自行创建状态码都没问题。

> 仅 记 录 在 RFC2616 上 的 HTTP 状 态 码 就 达 40 种， 若 再 加 上WebDAV（Web-based Distributed Authoring and Versioning，基于万维网的分布式创作和版本控制）（RFC4918、5842）和附加 HTTP 状态码（RFC6585）等扩展，数量就达 60 余种。别看种类繁多，实际上经常使用的大概只有 14 种。接下来，我们就介绍一下这些具有代表性的 14 个状态码。

### 2XX 成功

2XX 的响应结果表示请求被正常处理了。

#### 200 OK

![image-20220609093419624](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609093419624.png)

表示客户端发送的请求成功处理并返回响应的数据。

#### 204 No Content

![image-20220609093533296](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609093533296.png)

表示服务器成功处理但是返回的响应报文中不包含实体的主体部分。

一般在只需要从客户端往服务器发送信息，而对客户端不需要发送新信息内容的情况下使用。

#### 206 Partial Content

![image-20220609093654124](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609093654124.png)

该状态码表示客户端进行了范围请求，而服务器成功执行了这部分的 GET 请求。响应报文中包含由 Content-Range 指定范围的实体内容。

### 3XX 重定向

3XX 响应结果表明浏览器需要执行某些特殊的处理以正确处理请求。

#### 301 Moved Permanently

![image-20220609094118326](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609094118326.png)

永久性重定向。该状态码表示请求的资源已被分配了新的 URI，以后应使用资源现在所指的 URI。

当指定资源路径的最后忘记添加斜杠“/”，就会产生 301 状态码。

~~~bash
http://example.com/sample
~~~

#### 302 Found

![image-20220609094305036](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609094305036.png)

临时性重定向。该状态码表示请求资源已被分配到了新的 URI，希望用户能使用新的 URI 访问。

和 301 Moved Permanently 状态码相似，但 302 状态码代表的资源不是被永久移动，只是临时性质的。

#### 303 See Other

![image-20220609094550487](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609094550487.png)

该状态码表示由于请求对应的资源存在着另一个 URI，应使用 GET方法定向获取请求的资源。303 状态码和 302 Found 状态码有着相同的功能，但 303 状态码明确表示客户端应当采用 GET 方法获取资源，这点与 302 状态码有区别。

> 当 301、302、303 响应状态码返回时，几乎所有的浏览器都会把POST 改成 GET，并删除请求报文内的主体，之后请求会自动再次发送。
>
> 301、302 标准是禁止将 POST 方法改变成 GET 方法的，但实际使用时大家都会这么做。

#### 304 Not Modified

![image-20220609094739344](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609094739344.png)

该状态码表示客户端发送附带条件的请求时，服务器允许请求访问资源，但未满足条件的情况。304 状态码返回时，不包含任何响应的主体部分。304 虽然被划分在 3XX 类别中，但是和重定向没有关系。

#### 307 Temporary Redirect

临时重定向。该状态码与 302 Found 有着相同的含义。尽管 302 标准禁止 POST 变换成 GET，但实际使用时大家并不遵守。

307 会遵照浏览器标准，不会从 POST 变成 GET。但是，对于处理响应时的行为，每种浏览器有可能出现不同的情况。

### 4XX 客户端错误

4XX 的响应结果表明客户端是发生错误的原因所在。

#### 400 Bad Request

![image-20220609095014600](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609095014600.png)

该状态码表示请求报文中存在语法错误。

#### 401 Unauthorized

![image-20220609101243205](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609101243205.png)

该状态码表示发送的请求需要有通过 HTTP 认证（BASIC 认证、DIGEST 认证）的认证信息。另外若之前已进行过 1 次请求，则表示用户认证失败。

#### 403 Forbidden

![image-20220609101328535](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609101328535.png)

该状态码表明对请求资源的访问被服务器拒绝了。服务器端没有必要给出拒绝的详细理由，但如果想作说明的话，可以在实体的主体部分对原因进行描述，这样就能让用户看到了。

#### 404 Not Found

![image-20220609101413934](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609101413934.png)

该状态码表明服务器上无法找到请求资源。

### 5XX 服务器错误

5XX 的响应结果表明服务器本身发生错误。

#### 500 Internal Server Error

![image-20220609101524225](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609101524225.png)

该状态码表明服务器端在执行请求时发送了错误。

#### 503 Service Unavailable

![image-20220609101610934](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220609101610934.png)

该状态码表明服务器暂时处于超负载或正在进行停机维护，现在无法处理请求。如果事先得知解除以上状况需要的时间，最好写入 Retry-After 首部字段再返回给客户端。

> **状态码和状况的不一致：**
>
> 不少返回的状态码响应都是错误的，但是用户可能察觉不到这点。比如 Web 应用程序内部发生错误，状态码依然返回 200 OK，这种情况也经常遇到。
