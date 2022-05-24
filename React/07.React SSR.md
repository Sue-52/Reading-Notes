---
title: React SSR -- React 服务端渲染
date: 2022-04-11 16:10:00
categories:
  - React
tags:
  - React
---

## React SSR -- React 服务端渲染 

![01](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/01.png)

### 1. 概述

#### 1.1 渲染概述

##### 1. 服务端渲染 SSR

服务端渲染 ( server-side rendering ) 是指数据和 HTML 模板在服务端进行拼接，完成拼接后再发送到客户端进行解析。

![02](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/02.png)

##### 2. 客户端渲染 CSR

客户端渲染 ( client-side rendering ) 是指数据和 HTML 模板在客户端浏览器中进行拼接，拼接完成后再追加到 DOM 树中供浏览器解析。

![03](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/03.png)

##### 3. 静态生成 SSG

静态站点生成 ( static stie generation ) 是指在站点构建阶段进行数据和HTML模板的拼接并生成对应的静态的 HTML 页面。

#### 1.2 渲染发展史

##### 1. 传统意义上的服务器端渲染

传统意义上的服务器端渲染存在的问题主要是用户体验差：

1. 在网速比较慢的情况下，页面长时间处于白屏状态，用于等待时易产生焦虑。
2. 每次页面跳转都会重新加载整个页面体验差。

##### 2. 基于前端框架的客端户渲染

基于前端框架的客户端渲染虽然解决了传统服务端渲染用户体验差的问题，但也随之带来了新的问题：

客户端渲染不支持 SEO，导致页面很难被搜索引擎收录。

##### 3. 基于前端框架的服务端渲染

基于前端框架的服务端渲染解决了用户体验差的问题，也解决了 SEO 支持不友好的问题。

缺点是数据和HTML模板在服务端进行渲染，访问速度还是会受一些影响，而且服务端只能使用 JavaScript 运行时。

##### 4. 基于静态生成的服务端渲染

基于静态生成的服务端渲染在访问速度上是最具有优势的，也不存在 SEO 支持不友好的问题。

但是它只适用于页面内容不会发生频繁变化的场景，比如企宣，商城，博客，新闻等。

### 2. Next.js

#### 2.1 概述

[Next.js](https://nextjs.org/) 是集成式 React 服务端渲染应用框架，用于构建 SEO 友好的 SPA 应用。

```bash
# 全局安装 next.js 脚手架工具
npm install -g create-next-app
# 创建 next.js 应用
create-next-app next-tutorial
# 启动开发服务器
npm run dev
```

#### 2.2 基于文件系统的路由

##### 1. 路由匹配

在 Next.js 中，页面是存储在 pages 文件中的 React 组件，组件文件名称与路由相关联。

```react
// pages/index.js ====> http://localhost:3000/
export default function Home() {
  return <div>首页</div>;
}
```

```react
// pages/about.js ====> http://localhost:3000/about
export default function About() {
  return <div>关于我们</div>;
}
```

```react
// pages/post/index.js ====> http://localhost:3000/post
export default function Post() {
  return <div>这是博客索引目录</div>;
}
```

```react
// pages/blog/first-blog.js ====> http://localhost:3000/blog/first-post
export default function FirstPost () {
  return <div>这是我的第一篇博客文章</div>
}
```

```react
// pages/post/[pid].js ====> http://localhost:3000/post/1
import { useRouter } from "next/router";

export default function Post() {
  const router = useRouter(); // router.query ====> {"pid": "1"}
}
```

```react
// pages/post/[pid].js ====> http://localhost:3000/post/1?name=zhangsan&age=20
import { useRouter } from "next/router";

export default function Post() {
  const router = useRouter(); // routter.query ====> {"pid": "1", "name": "张三"}
}
```

```react
// pages/order/[uid]/[status].js ====> http://localhost:3000/order/2/all
import { useRouter } from "next/router";

export default function Orders() {
  const router = useRouter(); // router.query ====> {"uid": "2", "status": "all"}
}
```

```react
// pages/404.js ====> 自定义404页面
export default function NotFound() {
  return <div>这是自定义的404页面</div>;
}
```

##### 2. 路由跳转

Link 组件默认进行客户端路由跳转，如果浏览器中 JavaScript 被禁用则使用链接进行服务端路由跳转。

Link 组件中不应添加除 href 属性以外的属性，其余属性添加到 a 标签上，比如 title、onClick。

Link 组件通过预取(在生产中)功能自动优化应用程序以获得最佳性能。

```react
import Link from "next/link";

export default function Home() {
  return (
    <Link href="/about">
      <a title="关于我们"></a>
    </Link>
  );
}
```

```react
import Link from "next/link";

const posts = [
  { id: 1, title: "这是id为1的文章" },
  { id: 2, title: "这是id为2的文章" },
];

export default function Post() {
  return (
    <ul>
      {posts.map((post) => (
        <li key={post.id}>
          <Link href={`/post/${post.id}`}>
            <a>{post.title}</a>
          </Link>
        </li>
      ))}
    </ul>
  );
}
```

```react
import Link from "next/link";

const posts = [
  { id: 1, title: "这是id为1的文章" },
  { id: 2, title: "这是id为2的文章" },
];

export default function Post() {
  return (
    <ul>
      {posts.map((post) => (
        <li key={post.id}>
          <Link href={{ pathname: "/post/[pid]", query: { pid: post.id } }}>
            <a>{post.title}</a>
          </Link>
        </li>
      ))}
    </ul>
  );
}
```

```react
import { useRouter } from "next/router";

export default function Home() {
  const router = useRouter();
  return <button onClick={() => router.push("/about")}>关于我们</button>;
}
```

```react
import Link from "next/link";

export default function Home() {
  const onClickHandler = (event) => {
    alert("clicked");
    event.preventDefault();
  };
  return (
    <Link href="/about">
      <a onClick={onClickHandler}>关于我们</a>
    </Link>
  );
}
```

#### 2.3 API 路由

通过 API 路由开发者可以为**客户端**应用提供 API 接口。

API 路由是服务端应用程序，代码将会被打包到服务端应用程序，它不会增加客户端打包文件的体积。

##### 1. 基本使用

```javascript
// pages/api/index.js ====> http://localhost:3000/api
export default function handler(req, res) {
  // req: 请求对象
  // res: 响应对象
  // 对客户端进行响应
  res.send({ msg: "API Route is running" });
}
```

```javascript
// pages/api/posts/index.js
// 获取文章列表: GET  http://localhost:3000/api/posts
// 添加文章:    POST  http://localhost:3000/api/posts
export default function handler(req, res) {
  switch (req.method) {
    case "GET":
      res.send({ msg: "客户端在获取文章列表" });
      break;
    case "POST":
      res.send({ msg: "客户端在添加文章", body: req.body });
      break;
    default:
      res.status(400).send({msg: "API 不存在"})
  }
}
```

```javascript
// pages/api/posts/[pid].js
// 根据pid获取文章: GET     http://localhost:3000/api/post/12
// 根据pid删除文章: DELETE  http://localhost:3000/api/post/12
export default function handler(req, res) {
  switch (req.method) {
    case "GET":
      res.send({ msg: "客户端在根据pid获取文章", pid: req.query.pid });
      break;
    case "DELETE":
      res.send({ msg: "客户端在根据pid删除文章", pid: req.query.pid });
      break;
  }
}
```

```javascript
// pages/api/posts/[...pids].js 
// 根据pid批量删除文章: DELETE http://localhost:3000/api/posts/2/3
// [pid].js 的匹配优先级高于 [...pid].js
// req.query.pids => {pids: [2,3]}
export default function handler(req, res) {
  switch (req.method) {
    case "DELETE":
      res.send({ msg: "客户端在根据pid批量删除文章", pid: req.query.pids });
  }
}
```

##### 2. 连接数据库

```javascript
// services/dbConnection.js
import mongoose from "mongoose";

async function dbConnect() {
  // 判断数据库是否已经连接过, 如果已经连接过, 不再重复连接
  if (mongoose.connection.readyState === 1) return;
  // 如果数据库没有连接过, 链接数据库
  await mongoose.connect("mongodb://localhost:27017/test");
}
export default dbConnect;
```

```javascript
// models/Post.js
import mongoose from "mongoose";

const PostSchema = new mongoose.Schema({
  title: {
    type: String,
    required: [true, "标题不能为空"],
    unique: true,
    maxlength: [40, "标题不能超过40个字符"],
  },
  description: {
    type: String,
    required: true,
    maxlength: [200, "描述不能超过200个字符"],
  },
});
// posts
const Post = mongoose.models.Post || mongoose.model("Post", PostSchema);

export default Post;
```

```javascript
// pages/api/posts/index.js
import Post from "@/models/Post";
import dbConnect from "@/services/dbConnection";

export default async function handler(req, res) {
  await dbConnect();
  switch (req.method) {
    case "GET":
      const posts = await Post.find({});
      res.send({ success: true, posts });
      break;
    case "POST":
      const post = await Post.create(req.body);
      res.status(201).json({ success: true, post });
      break;
    default:
      res.status(400).send({ success: false, error: "api 不存在" });
  }
}
```

```json
// jsconfig.json
{
  "compilerOptions": {
    "baseUrl": ".",
    "paths": {
      "@/models/*": ["models/*"],
      "@/services/*": ["services/*"]
    }
  }
}
```

#### 2.4 静态生成

静态生成是指在构建阶段对应用程序进行编译，编译结果就是静态的 HTML 文件。

当客户端向服务端发送请求后，服务端直接将应用构建时编译的 HTML 文件发送到客户端。

默认情况下，如果组件不通过请求获取外部数据，Next.js 会在构建阶段将其编译为静态 HTML 文件。

预渲染适用于页面内容不会发生频繁变化的场景，比如博客、新闻、电商前台、文档、营销页面等。

```react
export default function About() {
  return <div>About</div>
}
```

##### 1. 基于页面组件的静态生成

在构建阶段如果组件需要获取外部数据，在组件中要导出名为 getStaticProps 的异步方法，通过它返回组件所需数据，它会在应用的构建阶段执行。

```react
import axios from "axios";

export default function Posts({ posts }) {
  return (
    <ul>
      {posts.map((post) => (
        <li key={post.id}>{post.title}</li>
      ))}
    </ul>
  );
}

export async function getStaticProps() {
  let { data } = await axios.get("https://jsonplaceholder.typicode.com/posts");
  return {
    props: {
      posts: data,
    },
  };
}
```

##### 2. 基于动态路由的静态生成

基于动态路由的静态生成是指根据路由动态参数编译 HTML 静态文件。

该路由拥有多少参数就会编译出多少静态 HTML 文件。

```bash
npm install -g json-server
```

```json
{
  "todos": [
    { "id": 1, "title": "吃饭" },
    { "id": 2, "title": "睡觉" },
    { "id": 3, "title": "打豆豆" }
  ]
}
```

```bash
json-server db.json -p 3001 -w
```

```react
// pages/todos/[id].js
import axios from "axios";
import { useRouter } from "next/router";

export default function Todo({ todo }) {
  const router = useRouter();
  if (router.isFallback) return <div>Loading...</div>;
  return (
    <div>
      {todo.id} {todo.title}
    </div>
  );
}

// 第一步: 在构建时先获取所有路由参数
export async function getStaticPaths() {
  return {
    paths: [
      {
        params: { id: "1" },
      },
      {
        params: { id: "2" },
      },
    ],
    // false 当访问没有被预渲染的路径时展示404页面
    // true: 当访问没有被预渲染的路径时, 先展示后备UI, Next.js 会在客户端请求时进行预渲染, 完后后显示预渲染结果
    fallback: true,
  };
}

// 第二步: 根据路由参数编译静态 HTML 文件
// 在构建时 Next 先调用 getStaticPaths 方法获取所有路由参数
// 遍历路由参数, 不断调用 getStaticProps 方法编译静态HTML文件
export async function getStaticProps({ params }) {
  let response = await axios.get(`http://localhost:3001/todos/${params.id}`);
  await delay(2000);
  return {
    props: {
      todo: response.data,
    },
    // 用于在构建站点后更新静态页面
    // 设置当前页面缓存的过期时间
    // 当前页面被访问时, 如果缓存时间过期, 触发当前页面的重新预渲染
    // 当次访问用户看到的仍然是缓存页面, 当重新预渲染完成后, 下次用户访问时看到的就是新页面了
    revalidate: 10,
  };
}

function delay(time) {
  return new Promise((resolve) => setTimeout(resolve, time));
}
```

#### 2.5 服务端渲染

服务端渲染是指在客户端发送请求时，服务器端即时编译 HTML，编译完成后将 HTML 代码发送到客户端。

服务端渲染方式适用于页面内容频繁发生变化场景且需要 SEO 的场景。

getServerSideProps 方法在服务端执行，内部可以调用 API 路由，也可以直接查询数据库。

```react
import Post from "@/models/Post";

export default function Posts({ posts }) {
  return (
    <ul>
      {posts.map((post, index) => (
        <li key={index}>
          <h1>{post.title}</h1>
          <p>{post.description}</p>
        </li>
      ))}
    </ul>
  );
}

export async function getServerSideProps() {
  const posts = await Post.find({});
  return {
    props: {
      posts: JSON.parse(JSON.stringify(posts)),
    },
  };
}
```

#### 2.6 混合渲染

混合渲染是指客户端渲染和服务端渲染、客户端渲染和静态生成可以混合使用。

比如文章详情页面，文章内容不会经常变化可以使用预渲染，而文章评论需要实时更新可以使用客户端渲染。

```react
// pages/api/comments/index.js
export default function comments(req, res) {
  res.send([
    { id: 1, content: "评论1" },
    { id: 2, content: "评论2" },
  ]);
}
```

```react
import axios from "axios";
import { useState, useEffect } from "react";

export default function Posts({ posts }) {
  const [comments, setComments] = useState([]);
  useEffect(() => {
    axios.get("http://localhost:3000/api/comments").then((response) => {
      setComments(response.data);
    });
  }, []);
  return (
    <>
      {/* 静态生成部分开始 */}
      <ul>
        {posts.map((post, index) => (
          <li key={index}>
            <h1>{post.title}</h1>
            <p>{post.description}</p>
          </li>
        ))}
      </ul>
      {/* 静态生成部分结束 */}
      {/* 动态渲染部分开始 */}
      <ul>
        {comments.map((comment) => (
          <li key={comment.id}>{comment.content}</li>
        ))}
      </ul>
      {/* 动态渲染部分结束 */}
    </>
  );
}

export async function getStaticProps() {
  let response = await axios.get("http://localhost:3000/api/posts");
  return {
    props: {
      posts: response.data.posts,
    },
  };
}
```

#### 2.7 为应用添加样式

Next.js 推荐将所有样式表文件存储在 styles 目录中。

##### 1. 全局样式

全局样式表应该在 _app.js 文件中被导入。

_app.js 文件中存储的是应用程序根组件。

```react
// pages/_app.js
import "../styles/globals.css";

function MyApp({ Component, pageProps }) {
  return <Component {...pageProps} />;
}

export default MyApp;
```

##### 2. 组件级样式

```react
import styles from '../styles/Home.module.css'

export default function Home() {
  return <div className={styles.container}></div>
}
```

#### 2.8 布局组件

##### 1. 情况一

应用中的每一个页面都有公共组件，且都是相同的公共组件，此时可以在根组件中使用布局组件。

```react
// components/Header.js
export default function Header() {
  return <div>Header</div>;
}
```

```react
// components/Footer.js
export default  function Footer() {
  return <div>Footer</div>;
}
```

```react
// components/Layout.js
import Footer from "./Footer";
import Header from "./Header";

export default function Layout({ children }) {
  return (
    <>
      <Header />
      {children}
      <Footer />
    </>
  );
}
```

```react
// pages/_app.js
import Layout from "../components/Layout";

export default function MyApp({ Component, pageProps }) {
  return (
    <Layout>
      <Component {...pageProps} />
    </Layout>
  );
}
```

##### 2. 情况二

应用中的页面有公共组件，但不是每一个页面都有相同的公共组件。

```react
// pages/about.js
import Layout from "../components/Layout";

export default function About() {
  return (
    <Layout>
      <div>About</div>
    </Layout>
  );
}
```

#### 2.9 Head 组件

通过 Head 组件可以为不同的页面设置不同的头信息，比如标题、描述、关键字等信息。

```react
// pages/about.js
import Head from "next/head";

export default function about() {
  return (
    <Head>
      <title>关于我们</title>
      <meta name="description" content="关于我们页面的描述内容" />
    </Head>
  );
}
```

每个页面中公共的头信息可以放在 _app.js 文件中。

```react
import Head from "next/head";

export default function MyApp({ Component, pageProps }) {
  return (
    <>
      <Head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
      </Head>
      <Component {...pageProps} />
    </>
  );
}
```

#### 2.10 Image 组件

使用 Image 组件加载图片可以优化图像体积、格式、图片懒加载。

```react
import Image from "next/image";

export default function about() {
  return (
    <>
      {[1, 2, 3, 4, 5].map((path) => (
        <div key={path}>
          <Image alt="" src={`/${path}.jpg`} width="280" height="420" />
        </div>
      ))}
    </>
  );
}
```

#### 2.11 环境变量

Next.js 内置对环境变量的支持。

| 文件名称         | 作用                                   |
| ---------------- | -------------------------------------- |
| .env             | 放置开发环境和生产环境中的公共变量     |
| .env.development | 放置开发环境变量，优先级高于 .env 文件 |
| .env.production  | 放置生产环境变量，优先级高于 .env 文件 |

```bash
# .env.development
API_URL=api.development.example.com
```

```bash
# .env.production
API_URL=api.production.example.com
```

```javascript
// 普通环境变量只在 Node.js 环境下起作用 ( API Route、getStaticProps、getServerSideProps )
process.env.API_URL
```

要在浏览器中使用环境变量，需要在环境变量的名字前面加 NEXT_PUBLIC_ 前缀

```bash
# .env.development
NEXT_PUBLIC_API_URL=api.production.example.com
```

在存储环境变量的文件中可以使用 $ 开头的变量指向系统环境变量，它用于指向系统中存储的敏感信息

```bash
# .env.development
SECRET_KEY=$SECRET
```

```bash
# ~/.zshrc (打开该文件手动写入)
export SECRET=test
source .zshrc
```

#### 2.12 构建命令

```bash
# 构建生成环境代码 (客户端应用程序、服务器端应用程序)
next build
# 启动用于生产的支持预渲染和服务端渲染的 node.js 服务器 (基于 next build 结果)
next start
# 启动开发环境的 node.js 服务器
next dev
# 将站点导出为静态HTML (基于 next build 结果)
# 不支持图片优化、api 路由
next export
```

### 3. 服务器端渲染原理

在服务器端渲染 React 应用程序，渲染结果就是静态的HTML代码。

#### 1. 应用目录结构介绍

```bash
├── build     						# 放置服务器端应用程序的打包文件
├── public    						# 服务器端设置的静态资源访问目录
├── src    							  # 源码目录
│   ├── client						# 客户端应用程序
│   ├── server             # 服务器端应用程序
│   └── shared						# 同构代码, 客户端和服务器端需要共用的代码, 比如页面组件、路由规则、Redux
├── package-lock.json      # 记录应用依赖的包的下载地址
├── package.json           # 应用工程文件
```

```bash
# 根据已有项目工程文件下载项目依赖
npm install
```

#### 2. 创建 web 服务器

目标：使用 express 框架创建 web 服务器。

```javascript
// src/server/index.js
// 导入 express 框架
import express from "express";
// 创建 web 服务器
const app = express();
// 设置静态资源文件夹
app.use(express.static("public"));

// 监听端口
app.listen(3000, () => console.log("服务器启动成功, 监听3000端口"));
```

#### 3. 服务器端渲染应用首页

目标：接收来自客户端的请求，在服务器端渲染首页页面组件，将渲染结果响应到客户端。

```react
// src/shared/pages/Home.js
import React from "react";

export default function Home() {
  return <div>HomePage works</div>;
}
```

```react
// src/server/index.js
import Home from "../shared/pages/Home";
import { renderToString } from "react-dom/server";
import React from "react";

app.get("/", (req, res) => {
  // 通过 renderToString 方法将 React 组件转换为 HTML 字符串
  const content = renderToString(<Home />);
  res.send(`
    <html>
      <head>
        <title>React 服务器端渲染</title>
      </head>
      <body>
        <div id="root">${content}</div>
      </body>
    </html>
  `);
});
```

#### 4. 服务端代码打包配置

```javascript
// webpack.server.js
const path = require("path");
const nodeExternals = require("webpack-node-externals");

module.exports = {
  mode: "development",
  entry: "./src/server/index.js",
  output: {
    path: path.join(__dirname, "build"),
    filename: "bundle.js",
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env", "@babel/preset-react"],
          },
        },
      },
    ],
  },
  // 在使用 webpack 进行服务器端应用程序打包时，webpack 将 Node 系统模块以及 node_modules 文件夹中的模块统统进行了打包，但其实这些模块是不需要被打包的，因为程序就在 Node 环境下运行，代码运行时所有的模块都在。
  // 忽略 node_modules 文件夹中的所有模块
  externals: [nodeExternals()],
  // 忽略 Node 内置模块，比如 path、fs 等
  target: "node",
  // 生成打包代码与源代码之间的映射关系
  devtool: "source-map",
};
```

```json
"scripts": {
  "dev:server-run": "nodemon --watch build --exec node build/bundle.js",
  // 通过webpack进行打包, 打包过程所使用的配置文件是 webpack.server.js, 监听文件变化, 重新打包
  "dev:server-build": "webpack --config webpack.server.js --watch"
}
```

#### 5. 为组件附加事件

```react
// src/shared/pages/Home.js
import React from "react";

export default function Home() {
  return <div onClick={() => alert("clicked")}>HomePage works</div>;
}
```

#### 6. 创建客户端入口文件

```react
// src/client/index.js
import React from "react";
import ReactDOM from "react-dom";
import Home from "../shared/pages/Home";

// hydrate: 渲染组件, 和 render 不同, 如果组件DOM结构已经存在, 复用DOM结构, 提升性能, 仅为组件附加事件
ReactDOM.hydrate(<Home />, document.getElementById("root"));
```

#### 7. 客户端代码打包配置

打包目标：转换 JSX 语法，转换浏览器不识别的现代 JavaScript 语法

打包位置：public 文件夹，它是服务端的静态资源文件夹

```javascript
// webpack.client.js
const path = require("path");

module.exports = {
  mode: "development",
  entry: "./src/client/index.js",
  output: {
    path: path.join(__dirname, "public"),
    filename: "bundle.js",
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env", "@babel/preset-react"],
          },
        },
      },
    ],
  },
  // 生成打包代码与源代码之间的映射关系
  devtool: "source-map",
};
```

```json
"scripts": {
  "dev:client-build": "webpack --config webpack.client.js --watch"
}
```

#### 8. 加载客户端打包代码

```react
app.get("/", (req, res) => {
  const content = renderToString(<Home />);
  res.send(`
    <html>
			<script src="/bundle.js"></script>
    </html>
  `);
});
```

#### 9. 合并 webpack 配置

```javascript
// webpack.base.js
module.exports = {
  // 开发环境
  mode: "development",
  // 配置打包规则
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env", "@babel/preset-react"],
          },
        },
      },
    ],
  },
  // 生成打包代码与源代码之间的映射关系
  devtool: "source-map",
};
```

```javascript
// webpack.client.js
const path = require("path");
const { merge } = require("webpack-merge");
const baseConfig = require("./webpack.base");

const clientConfig = {
  // 程序打包入口
  entry: "./src/client/index.js",
  // 配置程序打包出口
  output: {
    filename: "client.js",
    path: path.join(__dirname, "public"),
  },
};

module.exports = merge(baseConfig, clientConfig);
```

```javascript
// webpack.server.js
const path = require("path");
const { merge } = require("webpack-merge");
const nodeExternals = require("webpack-node-externals");
const baseConfig = require("./webpack.base");

const serverConfig = {
  // 程序打包入口
  entry: "./src/server/index.js",
  // 配置程序打包出口
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  },
  // 为了忽略 node_modules 文件夹中的所有模块
  externals: [nodeExternals()],
  // 为了忽略 path、fs 等内置模块
  target: "node",
};

module.exports = merge(baseConfig, serverConfig);
```

#### 10. 合并应用启动命令

```json
"scripts": {
  "dev": "npm-run-all --parallel dev:*"
},
```

#### 11. 独立渲染方法

```react
// src/server/render.js
import { renderToString } from "react-dom/server";
import React from "react";
import Home from "../shared/pages/Home";

export default function render() {
  const content = renderToString(<Home />);
  return `
    <html>
      <head>
        <title>React 服务器端渲染</title>
      </head>
      <body>
        <div id="root">${content}</div>
        <script src="/bundle.js"></script>
      </body>
    </html>
  `;
};
```

```react
// src/server/index.js
import render from "./render";

app.get("/", (req, res) => {
  res.send(render());
});
```

#### 12. 实现服务端路由

第一步：创建 List 页面，目的是测试路由是否能够配置成功。

```react
// 新增 List 页面
// src/shared/pages/List.js
import React from "react";

export default function List() {
  return <div>ListPage works</div>;
}
```

第二步：创建路由规则，由于客户端和服务端使用相同的路由规则，路由规则属于同构代码，所以路由配置文件放在 shared 文件夹下。

```react
// 创建路由规则
// src/shared/AppRoutes.js
import Home from "./pages/Home";
import List from "./pages/List";
import React from "react";
import { useRoutes } from "react-router-dom";

export const routes = [
  {
    path: "/",
    element: <Home />,
  },
  {
    path: "/list",
    element: <List />,
  },
  {
    path: "*",
    element: <div>not found</div>,
  },
];

export default function AppRoutes() {
  return useRoutes(routes);
}
```

第三步：配置服务端路由，StaticRouter 是专为服务端渲染准备的路由组件，它对标客户端的 BrowserRouter 组件。

```react
import { StaticRouter } from "react-router-dom/server";
import AppRoutes from "../shared/AppRoutes";

export default (req) => {
  // 根据请求地址进行路由规则匹配, 匹配到哪个页面组件就渲染哪个页面组件
  const content = renderToString(
    <StaticRouter location={req.path}>
      <AppRoutes />
    </StaticRouter>
  );
};
```

以上代码还不能运行，因为 react-router-dom/server 包中即包含 ES 模块还包含 MJS 模块，引入包时，在省略文件后缀的情况下，Node 会优先加载 MJS 模块，而 webpack 目前还不能识别 MJS 模块。

<img src="C:/Users/SUe/Documents/WeChat%2520Files/wxid_vaurgijoqqp622/FileStorage/File/2022-04/%25E8%25AE%25B2%25E4%25B9%2589/assets/images/63.png" align="left" width="35%"/>

第一种解决办法是引入包时明确指定要引入 ESModule 模块，即引包时不省略 .js 后缀。

```javascript
import { StaticRouter } from "react-router-dom/server.js";
```

第二种办法是让 webpack 识别 MJS 模块，将 MJS 模块当做 ESModule 进行解析。

```javascript
// webpack.server.js
const serverConfig = {
  resolve: {
    extensions: ["*", ".mjs", ".js", ".json"],
  },
  module: {
    rules: [
      {
        test: /\.mjs$/,
        include: /node_modules/,
        type: "javascript/esm",
      },
    ],
  },
};
```

第四步：将 Node 路由接收所有 GET 请求，接收到请求以后将请求移交 React 路由进行处理。

```react
// src/server/index.js
// 1. 服务端 express 接收任何请求, 然后将请求转发给 React 路由进行匹配
app.get("*", (req, res) => {
  res.send(render(req));
});
```

**注意：查看代码运行结果时要临时禁用浏览器 JavaScript，因为此时客户端程序还没有配置路由，客户端程序运行时会直接渲染首页组件，它会覆盖服务端返回的 HTML。**

#### 13. 实现客户端路由

```react
// src/client/index.js
import { BrowserRouter } from "react-router-dom";
import AppRoutes from "../shared/AppRoutes";

ReactDOM.hydrate(
  <BrowserRouter>
    <AppRoutes />
  </BrowserRouter>,
  document.getElementById("root")
);
```

```react
import React from "react";
import { Link } from "react-router-dom";

export default function Home() {
  return (
    <>
      <p>当前为首页</p>
      <Link to="/list">跳转到列表页面</Link>
    </>
  );
}
```

```react
import React from "react";
import { Link } from "react-router-dom";

export default function List() {
  return (
    <>
      <p>当前为列表页</p>
      <Link to="/">跳转到首页</Link>
    </>
  );
}
```

#### 14. 实现客户端 Redux

客户端与服务端共用除创建 Store 对象的代码。

```react
// src/shared/state/todo.slice.js
import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import axios from "axios";

export const loadTodos = createAsyncThunk("todos/loadTodos", () => {
  return axios
    .get("https://jsonplaceholder.typicode.com/todos")
    .then((response) => response.data);
});

const { reducer: TodosReducer } = createSlice({
  name: "todos",
  initialState: [],
  extraReducers: {
    [loadTodos.fulfilled](state, action) {
      action.payload.forEach((todo) => state.push(todo));
    },
  },
});

export default TodosReducer;
```

```react
// src/client/store.js
import { configureStore } from "@reduxjs/toolkit";
import TodosReducer from "../shared/state/todo.slice";

export default configureStore({
  reducer: {
    todos: TodosReducer,
  }
});
```

```react
// src/client/index.js
import { Provider } from "react-redux";
import store from "./store";

ReactDOM.hydrate(
  <Provider store={store}>
    <BrowserRouter>
      <AppRoutes />
    </BrowserRouter>
  </Provider>,
  document.getElementById("root")
);
```

```react
// src/shared/pages/List.js
import React, { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";
import { loadTodos } from "../state/todo.slice";

export default function List() {
  const dispatch = useDispatch();
  const todos = useSelector((state) => state.todos);
  useEffect(() => {
    dispatch(loadTodos());
  }, []);
  return (
    <ul>
      {todos.map((todo) => (
        <li key={todo.id}>{todo.title}</li>
      ))}
    </ul>
  );
}
```

**注意：客户端 Redux 代码必须在 List 组件中编写，而且要在首页通过客户端路由跳转到 List 页，不能直接访问 List，因为目前还没有配置服务端 Redux，如果直接访问，在服务端渲染组件，就会报错，错误信息是找不到 Store 中的数据，提示你尝试配置 Provider 组件。**

#### 15. 实现服务端 Redux

当服务器端接收到请求以后，先从 store 中获取组件所需要数据，数据获取完成后再使用数据渲染组件，渲染完成后再将结果响应到客户端。

1. 因为服务端并不知道当前页面需要什么数据，所以在页面组件要定义一个方法，告诉服务端它需要什么数据。
2. 为了能够让服务端获取到在组件中定义的获取数据的方法，我们要将该方法挂载到路由规则对象中。
3. 服务端接收到请求以后，动态创建 Store 对象，用于存储状态。
4. 服务端通过请求路径在路由规则数组中匹配出当前要使用的路由规则对象，从而获取组件中定义的获取数据的方法。
5. 当组件所需数据获取完成并被存储到 store 对象中以后，调用 render 方法渲染组件，此时组件就可以直接从 store 中获取状态了。

第一步：在组件文件中导出 loadStateFromStore 方法，该方法在服务端调用，用于向 store 对象中填充当前组件所需要的状态。

```react
// src/shared/pages/List.js
import { loadTodos } from "../state/todo.slice";

function loadStateFromStore(store) {
  return store.dispatch(loadTodos());
}

export default {
  element: <List />,
  loadStateFromStore,
};
```

第二步：重新配置组件路由规则，将 loadStateFromStore 方法挂载到组件配置对象中

```react
import List from "./pages/List";

export const routes = [
  {
    path: "/list",
    ...List,
  },
];
```

第三步：创建服务端 Store 对象，由于服务端是在接收到请求以后动态创建 Store，所以服务端创建 Store 的代码要写在一个方法中。

```react
// src/server/store.js
import { configureStore } from "@reduxjs/toolkit";
import TodosReducer from "../shared/state/todo.slice";

export default function createStore() {
  return configureStore({
    reducer: {
      todos: TodosReducer,
    },
  });
}
```

第四步：服务端在接收到请求以后动态创建 store，调用组件中的 loadStateFromStore 方法获取组件状态，组件状态获取完成后再渲染组件

```react
import createStore from "./store";
import { matchRoutes } from "react-router-dom";
import { routes } from "../shared/AppRoutes";

app.get("*", (req, res) => {
  // 创建 store 对象
  const store = createStore();
  // matchRoutes 方法用于在路由规则数组中匹配出当前要使用的规则
  // matchRoutes 方法的返回值是数组类型, 即使匹配到一个路由, 如果匹配不到返回 null
  const matchedRoutes = matchRoutes(routes, req.path);
  // 如果匹配到了路由规则
  if (Array.isArray(matchedRoutes)) {
    // 从路由规则中获取 loadStateFromStore 方法, 使用该方法获取组件需要的状态
    // 由于获取组件状态可能涉及异步操作, 所以该方法要求返回 Promise
    // 在 loadStateFromStore 方法中调用的 dispatch 方法正好返回 Promise, 所以在该方法中只需要返回 dispatch 方法的返回值即可
    // 此处我们将返回的所有 Promsie 放到一个数组中, 方便监听所有异步操作完成
    const loadDataArray = matchedRoutes.map(
      ({ route }) => route.loadStateFromStore && route.loadStateFromStore(store)
    );
    // 监听所有异步操作完成的状态
    // 所以异步操作完成就代表 Store 中已经存储了我们需要的数据了
    Promise.all(loadDataArray).then(() => {
      // 当 store 中有需要的数据以后再渲染组件
      res.send(render(req, store));
    });
  }
});
```

第五步：在服务端配置 Provider 组件

```react
import { renderToString } from "react-dom/server";
import { StaticRouter } from "react-router-dom/server";
import React from "react";
import { Provider } from "react-redux";
import AppRoutes from "../shared/AppRoutes";

export default (req, store) => {
  const content = renderToString(
    <Provider store={store}>
      <StaticRouter location={req.url}>
        <AppRoutes />
      </StaticRouter>
    </Provider>
  );
};
```

#### 16. 服务端数据回填客户端

警告原因：客户端 Store 在初始状态下是没有数据的，在渲染组件的时候生成的是空 ul，但是服务器端是先获取数据再进行的组件渲染，所以生成的是有子元素的ul，hydrate 方法在对比的时候发现两者不一致所以报了个警告。

<img src="C:/Users/SUe/Documents/WeChat%2520Files/wxid_vaurgijoqqp622/FileStorage/File/2022-04/%25E8%25AE%25B2%25E4%25B9%2589/assets/images/52.png" align="left" width="60%"/>

解决思路：将服务器端获取到的数据回填给客户端, 让客户端拥有初始数据。而且服务端已经获取了一次数据，客户端没有必要再次获取。

第一步：将组件状态挂载到 window 对象中

```react
// src/server/render.js
export default (req, store) => {
  // 获取初始状态
  const initialState = JSON.stringify(store.getState());
  return `
    <html>
			<script>window.initialState = ${initialState}</script>
			<script src="/bundle.js"></script>
    </html>
  `;
};
```

第二步：客户端设置初始状态

```react
export default configureStore({
  preloadedState: {
    todos: window.initialState.todos,
  },
});
```

第三步：在组件中判断如果初始数据不存在再进行初始数据的获取

```react
function List() {
  useEffect(() => {
    todos.length === 0 && dispatch(loadTodos());
  }, []);
}
```

#### 17. 防止XSS攻击

第一步：服务端模拟返回恶意XSS代码

```react
// src/shared/state/todo.slice.js
import { nanoid } from "@reduxjs/toolkit";
createSlice({
  extraReducers: {
    [loadTodos.fulfilled](state, action) {
      state.push({
        id: nanoid(),
        title: "</script><script>for(var i = 0; i < 2; i++){alert('逗你玩儿😝')}</script>",
      });
    },
  },
});
```

第二步：通过 serializeJavascript 方法对数据进行转换

```javascript
import serializeJavascript from "serialize-javascript";

export default (req, store) => {
  // 获取初始状态
  const initialState = serializeJavascript(store.getState());
};
```

#### 18. 设置页面头信息

[react-helmet](https://www.npmjs.com/package/react-helmet)

每个页面的独有的头信息就写在自己的组件里面。

```react
import { Helmet } from "react-helmet";

export default function Home() {
  return (
    <Helmet>
      <title>首页</title>
    </Helmet>
  );
}
```

```react
import { Helmet } from "react-helmet";

export default function List() {
  return (
    <Helmet>
      <title>列表页</title>
    </Helmet>
  );
}
```

每个页面公共的头信息写在布局组件中。

```react
import { Helmet } from "react-helmet";
import { Outlet } from "react-router-dom";

export default function Layout() {
  return (
    <>
      <Helmet>
        <meta charSet="utf-8" />
      </Helmet>
      <Outlet />
    </>
  );
}
```

将布局组件配置在路由信息中。

```react
import Layout from "./pages/Layout";

export const routes = [
  {
    path: "/",
    element: <Layout />,
    children: [
      {
        path: "",
        element: <Home />,
      }
    ],
  },
];
```

