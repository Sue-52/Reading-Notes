---
title: React Router -- React 路由管理
date: 2022-04-11 15:25:00
categories:
  - React
tags:
  - React
---

## React Router -- React 路由管理

### 1. 客户端路由概述

在 Web 应用中，客户端路由就是导航，就是 URL 地址与页面之间的对应关系，可以实现点击不同的链接跳转到不同的页面。

传统 Web 应用的中的路由是由 a 标记实现的，通过 a 标记可以实现在不同的 HTML 文件之间进行跳转。

在 React 应用中，只有一个 HTML 文件，React 应用通过不同的组件模拟不同的页面，所以 React 应用中的路由要实现的是在不同的组件之间进行跳转。

![image-20220411152527293](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220411152527293.png)

示例图：

![42](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/42.gif)

```bash
npm install react-router-dom
```

### 2. 基本使用

需求：为应用创建首页和新闻两个页面。

1. 创建页面级路由组件

   `src/pages/Home.js`

   ```react
   function Home() {
     return <div>欢迎来到首页 🌶🌶🌶 </div>;
   }
   export default Home;
   ```

   `src/pages/News.js`

   ```react
   function News() {
     return <div>欢迎来到关于新闻页 😁😁😁</div>;
   }
   export default News;
   ```

   `src/pages/Error.js`

   ```react
   function Error() {
     return <div>页面走丢了 😭😭😭</div>;
   }
   export default Error;
   ```

2. 配置路由规则

   `src/App.js`

   ```react
   import { BrowserRouter, Routes, Route } from "react-router-dom";
   import News from "./pages/News";
   import Home from "./pages/Home";
   
   function App() {
     // 注意: 在 v6 版本中，一旦路由规则匹配成功，则不再继续向后匹配，所以不再需要使用 exact 属性
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/" element={<Home />} />
           <Route path="/news" element={<News />} />
         </Routes>
       </BrowserRouter>
     );
   }
   
   export default App;
   ```

3. 为应用添加用于跳转页面的链接地址

   ```react
   import { Link } from "react-router-dom";
   
   function App() {
     // 注意: react-router-dom 提供的组件都必须被 BrowserRouter 组件包裹, 包括 Link 组件
     return (
       <BrowserRouter>
         <Link to="/">Home</Link>
         <Link to="/news">News</Link>
       </BrowserRouter>
     );
   }
   ```

### 3. NavLink 组件

Link 组件是用于生成普通链接的组件，导航链接应该使用 NavLink 组件，当前链接被激活时，链接元素身上会自动添加 active 激活类名。

```react
<NavLink to="/">
  Home
</NavLink>
<NavLink to="/news">
  News
</NavLink>
```

可以通过以下方式更改默认的激活类名。

 ```react
 const activeClassName = ({ isActive }) => (isActive ? "on" : "off");
 
 <NavLink to="/" className={activeClassName}>
   Home
 </NavLink>
 <NavLink to="/about" className={activeClassName}>
   News
 </NavLink>
 ```

通过同样的方式也可以为导航链接添加行内样式。

```react
<NavLink to="/" style={({ isActive }) => ({ color: isActive ? "red" : "blue" })}>
  Home
</NavLink>
```

### 4. 404 与 Navigate

在路由规则配置的最后，可以使用 `*` 号匹配不存在的路由规则，匹配到以后可以指定表示 404 的页面组件。

```react
import Error from "./pages/Error";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="*" element={<Error />} />
      </Routes>
    </BrowserRouter>
  );
}
```

如果不想展示 404，也可以将路由重定向到应用中已经存在的页面路由组件。

```react
import { Navigate } from "react-router-dom";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="*" element={<Navigate to="/" />} />
      </Routes>
    </BrowserRouter>
  );
}
```

### 5. 嵌套路由

嵌套路由可以理解为二级路由乃至三级路由. 就是在路由组件中还包含路由匹配组件。

![40](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/40.png)

1. 配置新闻页面中的二级路由规则

   `src/App.js`

   ```react
   import News from "./pages/News";
   import InnerNews from "./pages/InnerNews";
   import OuterNews from "./pages/OuterNews";
   
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/news" element={<News />}>
             <Route path="inner" element={<InnerNews />} />
             <Route path="outer" element={<OuterNews />} />
           </Route>
         </Routes>
       </BrowserRouter>
     );
   }
   ```

2. 在一级路由页面组件 ( 新闻页面组件 ) 中放置路由插槽、配置跳转链接

   `src/pages/News.js`

   ```react
   import { NavLink, Outlet } from "react-router-dom";
   
   function News() {
     return (
       <div>
         <p>欢迎来到关于新闻页 😁😁😁</p>
         <NavLink to="/news/inner">国内新闻</NavLink>
         <NavLink to="/news/outer">国际新闻</NavLink>
         <Outlet />
       </div>
     );
   }
   ```

### 6. 索引路由

通过索引路由可以指定默认显示的二级路由，比如上述案例中，当进入新闻页面时二级路由组件所在区域是空白的，该缺陷就可以通过索引路由补救。

`src/App.js`

```react
function App() {
  // 注意: 索引路由不能有 path
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/news" element={<News />}>
          <Route index element={<InnerNews />} />
          <Route path="inner" element={<InnerNews />} />
          <Route path="outer" element={<OuterNews />} />
        </Route>
      </Routes>
    </BrowserRouter>
  );
}
```

### 7. 编程式导航

通过事件的方式进行跳转。

```react
import { useNavigate } from "react-router-dom";

function Home() {
  const navigate = useNavigate();
  return <button onClick={() => navigate("/news")}>News</button>;
}
```

### 8. 路由参数

通过路由参数可以实现在不同的页面组件之间跳转时携带数据。

比如在文章列表页面中，点击某一篇文章跳转到文章详情页面，此时就需要将被点击的那篇文章的 id 传递到文章详情页面。

在应用中会有很多篇文章，但是文章详情页面组件只有一个，可以将它理解为文章详情的模板页面，在跳转到这个模板页面时，需要将文章id传进来，在模板页面中需要通过 id 获取详情，从而展示详情数据。

1. 添加路由规则并指定跳转到该路由时需要传递参数

   `src/App.js`

   ```react
   import Detail from "./pages/Detail";
   
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/detail/:id" element={<Detail />} />
         </Routes>
       </BrowserRouter>
     );
   }
   ```

2. 在实现跳转的路由链接中传递参数

   `src/pages/Home.js`

   ```react
   import { Link } from "react-router-dom";
   
   function Home() {
     return (
       <ul>
         <li>
           <Link to="/detail/1">老旧小区改造, 这三区名单来了!</Link>
         </li>
         <li>
           <Link to="/detail/2">穿鞋把脚放列车座位上, 韩总统候选人尹锡悦引发网友批..</Link>
         </li>
       </ul>
     );
   }
   ```

3. 在目标跳转页面组件接收路由参数

   `src/pages/Detail.js`

   ```react
   import { useParams } from "react-router-dom";
   
   function Detail() {
     const { id } = useParams();
     return <div>Detail Page {id}</div>;
   }
   
   export default Detail;
   ```

### 9. 查询参数

1. 定义路由时不需要加路由参数占位符

   `src/App.js`

   ```react
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/detail" element={<Detail />} />
         </Routes>
       </BrowserRouter>
     );
   }
   ```

2. 在链接跳转时添加参数

   `src/pages/Home.js`

   ```react
   import { Link } from "react-router-dom";
   
   function Home() {
     return (
       <ul>
         <li>
           <Link to="/detail?id=1">老旧小区改造, 这三区名单来了!</Link>
         </li>
         <li>
           <Link to="/detail?id=2">穿鞋把脚放列车座位上, 韩总统候选人尹锡悦引发网友批..</Link>
         </li>
       </ul>
     );
   }
   ```

3. 在目标跳转页面组件接收路由参数

   `src/pages/Detail.js`

   ```react
   import { useSearchParams } from "react-router-dom";
   
   function Detail() {
     const [searchParams] = useSearchParams();
     return <div>Detail Page {searchParams.get("id")}</div>;
   }
   
   export default Detail;
   ```

### 10. 路由组件懒加载

默认情况下应用中所有的组件都被打包到了同一个文件中，就是说应用初始加载时就加载了所有的组件，这样会导致初始加载应用时间长用户体验差。

解决办法就是在打包应用时以页面组件为单位，将不同的页面组件打包到不同的文件中，初始加载时只加载用户访问的页面组件。

1. 通过 lazy, import 异步加载组件

   `src/App.js`

   ```react
   import { lazy } from 'react';
   
   const Home = lazy(() => import(/* webpackChunkName: "Home" */ "./pages/Home"));
   ```

   通过 import 方法动态导入模块时，webpack 会将导入的模块拆分成单独的文件。

   webpackChunkName 定义拆分文件名称。

2. 在调用异步加载的组件时，组件的外面必须包裹 Suspense 组件，通过 Suspense 组件可以指定组件加载过程中的等待 UI。

   `src/App.js`

   ```react
   import { Suspense } from "react";
   
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route
             path="/"
             element={
               <Suspense fallback={<div>loading...</div>}>
                 <Home />
               </Suspense>
             }
           />
         </Routes>
       </BrowserRouter>
     );
   }
   ```

3. 封装 Loadable 组件以复用 Suspense 组件

   `src/common/Loadable.js`

   ```react
   import { Suspense } from "react";
   
   function Loadable(Component) {
     return function (props) {
       return (
         <Suspense fallback={<div>loading...</div>}>
           <Component {...props} />
         </Suspense>
       );
     };
   }
   
   export default Loadable;
   ```

   `src/App.js`

   ```react
   import Loadable from "./pages/Loadable";
   
   const Home = Loadable(
     lazy(() => import(/* webpackChunkName: "Home" */ "./pages/Home"))
   );
   
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/" element={<Home />}/>
         </Routes>
       </BrowserRouter>
     );
   }
   ```


### 11. 路由守卫 单路由守卫

当用户去访问那些需要鉴权以后才能进入的路由组件时，需要先通过路由守卫对其进行鉴权，只有通过才允许用户进入，否则进行重定向。

1. 定义执行鉴权的钩子函数供路由守卫进行使用

   `src/common/useAuth.js`

   ```react
   import { useEffect, useState } from "react";
   
   function isAuth() {
     // 模拟鉴权成功
     return Promise.resolve();
     // 模拟鉴权失败
     // return Promise.reject();
   }
   
   function useAuth() {
     // 用于存储鉴权结果
     // true 成功
     // false 失败 (默认值)
     const [auth, setAuth] = useState(false);
     // 用于存储异步状态
     // true 等待 (默认值)
     // false 结束
     const [loading, setLoading] = useState(true);
     useEffect(() => {
       // 开始鉴权
       isAuth()
         // 成功
         .then(() => setAuth(true))
         // 失败
         .catch(() => setAuth(false))
         // 不管成功还是失败, 都将异步状态更新为结束
         .finally(() => setLoading(false));
     }, []);
     // 返回异步状态和鉴权结果
     return { loading, auth };
   }
   
   export default useAuth;
   ```

2. 创建用于实现身份验证的路由守卫组件

   `src/common/AuthGuard.js`

   ```react
   import { Navigate } from "react-router-dom";
   import useAuth from "../hooks/useAuth";
   
   function AuthGuard({ children }) {
     // 调用鉴权钩子, 获取异步状态及鉴权结果
     const { auth, loading } = useAuth();
     // 如果异步状态为等待, 渲染等待过程中的UI界面
     if (loading) return <div>loading...</div>;
     // 判断鉴权结果, 如果通过, 进入目标路由组件, 如果没通过, 重定向到执行授权的页面
     return auth ? children : <Navigate to="/login" />;
   }
   
   export default AuthGuard;
   ```

3. 对 Admin 组件，即需要鉴权以后才能访问的页面路由组件进行守卫

   `src/App.js`

   ```react
   import AuthGuard from "./common/AuthGuard";
   
   function App() {
     return (
       <BrowserRouter>
         <Routes>
           <Route path="/admin" element={<AuthGuard><Admin /></AuthGuard>}/>
         </Routes>
       </BrowserRouter>
     );
   }
   ```

### 12. 路由守卫 多路由守卫

通过 Outlet 路由插座组件可以实现多路由守卫。

`src/App.js`

```react
import Admin from "./pages/Admin";
import AuthGuardOutlet from "./common/AuthGuardOutlet";

function App() {
  return (
    <BrowserRouter>
        <Route path="/admin" element={<AuthGuardOutlet />}>
          <Route path="" element={<Admin />} />
        </Route>
      </Routes>
    </BrowserRouter>
  );
}
```

`src/common/AuthGuardOutlet.js`

```react
import { Navigate, Outlet } from "react-router-dom";
import useAuth from "../hooks/useAuth";

function AuthGuardOutlet() {
  // 调用鉴权钩子, 获取异步状态及鉴权结果
  const { auth, loading } = useAuth();
  // 如果异步状态为等待, 渲染等待过程中的UI界面
  if (loading) return <div>loading...</div>;
  // 判断鉴权结果, 如果通过, 渲染路由插座组件, 让 children 组件能够渲染到插座组件中
  // 如果没通过, 重定向到执行授权的页面
  return auth ? <Outlet /> : <Navigate to="/login" />;
}

export default AuthGuardOutlet;
```

### 13. 滚动行为修正

问题：在 A 页面中将页面滚动到底部，切换到 B 页面，此时滚动条仍处于 A 页面的位置。

解决问题的方式就是监听路由切换行为，当路由发生切换行为时，让页面自动回到顶部。

`src/common/ScrollTop.js`

```react
import { useEffect } from "react";
import { useLocation } from "react-router-dom";

function ScrollTop() {
  const { pathname } = useLocation();
  useEffect(() => {
    window.scrollTo(0, 0);
  }, [pathname]);
  return null;
}

export default ScrollTop;
```

`src/App.js`

```react
import ScrollTop from "./common/ScrollTop";

function App() {
  return (
    <BrowserRouter>
      <ScrollTop />
    </BrowserRouter>
  );
}
```

### 14. useRoutes

通过 useRoutes 钩子函数可以实现通过 JavaScript 配置对象的方式定义路由规则。

`src/AppRoute.js`

```react
import { useRoutes } from "react-router-dom";
import Home from "./pages/Home";
import InnerNews from "./pages/InnerNews";
import News from "./pages/News";
import OuterNews from "./pages/OuterNews";

const routes = [
  { path: "/", element: <Home /> },
  {
    path: "/news",
    element: <News />,
    children: [
      { path: "inner", element: <InnerNews /> },
      { path: "outer", element: <OuterNews /> },
    ],
  },
]

function AppRoute() {
  let element = useRoutes(routes);
  return element;
}

export default AppRoute;
```

`src/App.js`

```react
import { BrowserRouter } from "react-router-dom";
import AppRoute from "./AppRoute";

function App() {
  return (
    <BrowserRouter>
      <AppRoute />
    </BrowserRouter>
  );
}

export default App;
```

### 15. 嵌套路由与布局组件

```react
// src/App.js
import { BrowserRouter, Route, Routes } from "react-router-dom";
import AdminHome from "./admin/AdminHome";
import AdminLayout from "./admin/AdminLayout";
import Layout from "./components/Layout";
import About from "./pages/About";
import Home from "./pages/Home";

export default  function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Layout />}>
          <Route path="" element={<Home />} />
          <Route path="/about" element={<About />} />
        </Route>
        <Route path="/admin" element={<AdminLayout />}>
          <Route path="" element={<AdminHome />} />
        </Route>
      </Routes>
    </BrowserRouter>
  );
}
```

```react
import Header from "./Header";
import Footer from "./Footer";
import { Outlet } from "react-router-dom";

export default function Layout() {
  return (
    <>
      <Header />
      <Outlet />
      <Footer />
    </>
  );
}
```

