---
title: React Appendix -- React 附录
date: 2022-04-14 21:45:00
categories:
  - React
tags:
  - React
---

## React Appendix -- React 附录

### 1. 类组件

#### 1.1 创建类组件

```react
import React, { Component } from 'react';

class Person extends Component {
  render () {
    return <div>Hello I am a class component</div>
  }
}

export default Person;
```

#### 1.2 向类组件内部传递属性

```react
<Person name="张三" age={20}/>
```

```react
class Person extends Component {
  render() {
    const { name, age } = this.props
    return (
      <div>
        <span>{name}</span>
        <span>{age}</span>
      </div>
    )
  }
}
```

#### 1.3 Props 默认值

```react
class Person extends Component {
  static defaultProps = {}
}
```

#### 1.4 组件状态

```react
class Person extends Component {
  constructor(){
    super();
    this.state = {
      name: "张三",
      age: 20
    }
    this.onClickHandler = this.onClickHandler.bind(this);
  }
  
 	onClickHandler() {
    this.setState({ ...this.state, name: "李四" });
  }

  render() {
    return (
      <>
        <span>{this.state.name}</span>
        <span>{this.state.age}</span>
      	<button onClick={this.onClickHandler}>更改数据</button>
      </>
    )
  }
}
```

#### 1.5 类组件生命周期函数

##### 1.5.1 概述

生命周期如同四季更替，一个人的生、老、病、死，在每个特殊的年龄阶段，做着不同的事情。

组件也有生命周期，从组件被创建、被挂载到DOM中、直到从 DOM 中移除，这就是组件的生命周期。在组件生命周期的不同阶段，React 提供了对应的生命周期函数，让我们在不同阶段做不同的事情。这些函数将会被 React 自动调用执行。

生命周期大致分为三个部分：挂载、更新和卸载。

##### 1.5.2 组件挂载

当组件被创建并且被整体插入到 DOM 中叫做是挂载组件，在组件被创建和挂载的过程中以下方法被调用：

```javascript
constructor()         // 设置组件的初始配置
render()              // 解析 JSX, 渲染DOM, 呈递用户界面
componentDidMount()   // 组件挂载完成后执行, 放置所有和DOM相关的操作，比如发送Ajax请求、设置定时器、添加事件监听、获取DOM元素
```

##### 1.5.3 组件更新

当组件状态发生变化时，组件重新渲染。

```javascript
shouldComponentUpdate(nextProps, nextState)
render
componentDidUpdate
```

##### 1.5.3 组件卸载

组件卸载是指将组件从 DOM 中删除。

```react
componentWillUnmount   // 这个方法在组件从 DOM 中移除之前调用. 方法中可以执行清理工作. 例如删除事件监听, 清除定时器
```

#### 1.6 上下文

1. 创建 Context 上下文对象, 导出 Provider 组件

   ```react
   // TestContext.js
   import { createContext } from "react"
   
   export const TestContext = createContext()
   
   export function TestProvider({ children, value }) {
     return <TestContext.Provider value={value}>{children}</TestContext.Provider>
   }
   ```

2. 将状态存储到上下文对象中

   ```react
   import ReactDOM from "react-dom"
   import App from "./App"
   import { TestProvider } from "./TestContext"
   
   ReactDOM.render(
     <TestProvider value={{ test: "test" }}>
       <App />
     </TestProvider>,
     document.getElementById("root")
   )
   ```

3. 在组件中获取上下文对象中的状态

   ```react
   import { Component } from "react"
   import { TestContext } from "./TestContext"
   
   class App extends Component {
     render() {
       return (
         <div>
           <TestContext.Consumer>
             {context => <div>{context.test}</div>}
           </TestContext.Consumer>
         </div>
       )
     }
   }
   
   export default App
   ```

4. 在组件中获取上下文的另一种方式

   ```react
   import { Component } from "react"
   import { TestContext } from "./TestContext"
   
   class App extends Component {
     static contextType = TestContext
     render() {
       return <div>{this.context.test}</div>
     }
   }
   
   export default App
   ```

#### 1.7 错误边界

默认情况下，组件渲染错误会导致整个应用程序中断，创建错误边界可确保在特定组件发生错误时应用程序不会中断。

错误边界是一个 React 组件，可以捕获子级组件在渲染时发生的错误，当错误发生时可以将错误记录下来，可以显示备用 UI 界面。

错误边界涉及到两个生命周期函数，分别为 getDerivedStateFromError 和 componentDidCatch。

getDerivedStateFromError 为静态方法，方法中需要返回一个对象，该对象会和state对象进行合并，用于更改应用程序状态。

componentDidCatch 方法用于记录应用程序错误信息，该方法的参数就是错误对象。 

```react
// ErrorBoundaries.js
import React from "react"
import App from "./App"

export default class ErrorBoundaries extends React.Component {
  constructor() {
    super()
    this.state = {
      hasError: false
    }
  }
  componentDidCatch(error) {
    console.log("componentDidCatch")
  }
  static getDerivedStateFromError() {
    console.log("getDerivedStateFromError")
    return {
      hasError: true
    }
  }
  render() {
    if (this.state.hasError) {
      return <div>发生了错误</div>
    }
    return <App />
  }
}
```

```react
// App.js
import React from "react"

export default class App extends React.Component {
  render() {
    // throw new Error("lalala")
    return <div>App works</div>
  }
}
```

```react
// index.js
import React from "react"
import ReactDOM from "react-dom"
import ErrorBoundaries from "./ErrorBoundaries"

ReactDOM.render(<ErrorBoundaries />, document.getElementById("root"))
```

#### 1.8 渲染属性

渲染属性是 React 中实现逻辑复用的一种高级技巧。

```react
// Resizeable.js
import React, { useEffect, useState } from "react"

function Resizeable({ render }) {
  const [sizes, setSizes] = useState([window.innerWidth, window.innerHeight])
  useEffect(() => {
    window.addEventListener("resize", () => {
      setSizes([window.innerWidth, window.innerHeight])
    })
  }, [])
  return render(sizes)
}

export default Resizeable
```

```react
// index.js
import React from "react"
import ReactDOM from "react-dom"
import Resizeable from "Resizeable"
import App from "./App"

ReactDOM.render(
  <Resizeable render={sizes => <App sizes={sizes} />} />,
  document.getElementById("root")
)
```

```react
// App.js
import React from "react"

function App({ sizes }) {
  return <div>{JSON.stringify(sizes)}</div>
}

export default App
```

#### 1.9  高阶组件

高阶组件用于共享代码，增加逻辑复用。

高阶组件是一种模式，一个函数接收组件作为参数，返回一个新的组件。

函数名称通常以with开头，接收的组件形参名称为 WrappedComponent，返回的组件名称和函数名称一样，只不过with中的w要大写。

```react
function withResizable(WrappedComponent, number) {
  class WithResizable extends Component {
    constructor() {
      this.state = {
        size: [window.innerWidth, window.innerHeight],
      };
    }
    onResize = () => {
      this.setState({
        size: [window.innerWidth * number, window.innerHeight],
      });
    };
    componentDidMount() {
      window.addEventListener("resize", this.onResize);
    }
    componentWillUnMount() {
      window.removeEventListener("resize", this.onResize);
    }
    render() {
      return <WrappedComponent size={this.state.size} {...this.props} />;
    }
  }
  return WithResizable;
}
```

```react
class Foo extends Component {
  render () {
    const size = this.props.size;
    return <div>{size[0]} --- {size[1]}</div>
  }
}

const WrapperedFoo = withResizable(Foo, 10);
export default WrapperedFoo;
```

```react
<WrapperedFoo hello="world"/>
```

### 2. 配置路径别名

1. 下载 `@craco/craco` 用于覆盖 `create-react-app` 脚手架工具自动生成的配置

   ```bash
   npm install @craco/craco
   ```

2. 在应用根目录下创建 `craco.config.js` 配置文件并加入路径别名配置

   ```javascript
   const path = require("path");
   
   module.exports = {
     webpack: {
       alias: {
         "@component": path.resolve(__dirname, "src/components/"),
         "@layouts": path.resolve(__dirname, "src/components/layouts"),
         "@pages": path.resolve(__dirname, "src/components/pages"),
         "@shared": path.resolve(__dirname, "src/components/shared"),
         "@state": path.resolve(__dirname, "src/state"),
       },
     },
   };
   ```

3. 修改 `package.json` 文件中的应用启动命令

   ```json
   {
     "scripts": {
       "start": "craco start",
       "build": "craco build",
       "test": "craco test"
     }
   }
   ```

4. 在应用根目录下创建 `jsconfig.json` 文件，加入路径别名的配置，该配置用于让编译器识别路径别名。

   ```json
   {
     "compilerOptions": {
       "paths": {
         "@component/*": ["./src/components/*"],
         "@layouts/*": ["./src/components/layouts/*"],
         "@pages/*": ["./src/components/pages/*"],
         "@shared/*": ["./src/components/shared/*"],
         "@state/*": ["./src/state/*"]
       }
     },
     "include": ["src"]
   }
   ```


一般建议把不依赖props和state的函数提到你的组件外面，把那些仅被useEffect使用的函数放到useEffect里面。

如果在 useEffect 里面用到了组件内的函数或者通过 props 传递过来的函数，建议在创建函数的地方使用 useCallback 包裹函数并指定依赖项。

每次组件重新渲染，所有的东西都属于这次特定渲染，包括 props、state、事件处理函数、effect 等等。

