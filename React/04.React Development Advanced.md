---
title: React Development Advanced -- 组件开发进阶
date: 2022-04-06 20:55:00
categories:
  - React
tags:
  - React
---

## React Development Advanced -- 组件开发进阶

> 目标：
>
> 1. useState (声明状态)
> 2. useReducer (状态管理)
> 3. useLayoutEffect (副作用代码处理)
> 4. useRef (获取元素 DOM 对象)
> 5. memo (优化渲染)
> 6. useMemo (缓存状态)
> 7. useCallback (缓存方法)
> 8. useImperativeHandle (子父通讯)
> 9. Custom Hooks (自定义 hooks)
> 10. Children (进一步优化 props.children)
> 11. Context (组件状态共享)

进一步的对 hook 方法的了解和学习。

### 1. useState

> 目标：
>
> 1. 状态异步更新
> 2. 状态覆盖
> 3. 状态合并
> 4. 初始化状态函数

#### 1.1 状态异步更新

设置状态的方法在调用后不会立即更新视图，而是要等到当前执行栈中所有代码执行完成以后在更新视图，这是为了防止视图被频繁更新导致性能降低。

~~~react
import { useState } from "react";

function App() {
  const [count, setCount] = useState(0);
  const onClickHandler = () => {
    setCount(count + 1);
    console.log(count); // 此处的输出 count 值总是未更新前的
  };
  return <button onClick={onClickHandler}>{count}</button>;
}
~~~

如果开发者就想在 count 被更新后执行一些操作，可以通过 useEffect 方法监听状态变化。

#### 1.2 状态覆盖

多次调用更新状态的方法，如果参数类型不为函数，那么React内部会进行状态的覆盖。

只有最后一个状态才会生效。

~~~react
function App() {
  const [obj, setObj] = useState({});
  const onClickHandler = () => {
    setObj({ a: 1 });
    setObj({ b: 1 });
    setObj({ c: 1 });
    setObj({ d: 1 });
    // 最终的状态结果就是 { d: 1 }
    // 注意这里是状态对象整体覆盖，而不是属性合并
  };
  return <button onClick={onClickHandler}>{JSON.stringify(obj)}</button>;
}
~~~

#### 1.3 状态合并

如果参数为函数，并进行多次的调用，那么会进行状态的合并，一步一步按照函数顺序执行。

函数的第一个参数保存和状态的初始值

~~~react
function App() {
  const [obj, setObj] = useState({});
  const onClickHandler = () => {
    setObj((prev) => ({ ...prev, a: 1 }));
    setObj((prev) => ({ ...prev, b: 1 }));
    setObj((prev) => ({ ...prev, c: 1 }));
    setObj((prev) => ({ ...prev, d: 1 }));
    // 最终的状态结果就是 { a: 1, d: 1, c: 1, d: 1 }
    // 每一个 prev 参数都是上一次合并的结果
  };
  return <button onClick={onClickHandler}>{JSON.stringify(obj)}</button>;
}
~~~

#### 1.4 初始化状态函数

在使用 useState 方法生命状态时，状态初始值只在组件渲染使用，以后的每次组件渲染中都不会使用，但是如果初始值中包含昂贵的计算，在每次组件重新渲染时都会被执行，导致组件性能变差。

`问题代码：`

~~~react
import { useState } from "react";

function App() {
  let inialState = 0;
  for (let i = 0; i < 100000000; i++) {
    inialState += i;
  }
  const [number, setNumber] = useState(inialState);
  return (
    <button onClick={() => setNumber((prev) => prev + 1)}>{number}</button>
  );
}

export default App;
~~~

问题：

- 门当组件重新渲染，for 循环都会执行一次，浪费了大量的性能。

如果将初始状态的代码放入 useState 中，那么只会在初始状态函数调用时使用

`解决问题：`

~~~react
import { useState } from "react";

function App() {
  const [number, setNumber] = useState(() => {
    let inialState = 0;
    for (let i = 0; i < 100000000; i++) {
      inialState += i;
    }
    return inialState;
  });
  return (
    <button onClick={() => setNumber((prev) => prev + 1)}>{number}</button>
  );
}

export default App;
~~~

### 2. useReducer

useReducer 是另一种在组件中声明状态管理的方式，适用于逻辑复杂的场景，相当于 useState 的增强方案。

React 组件本身之应该包含用户界面的渲染逻辑，而用户在操作状态的CRUD时，通常情况使用 useState 在内部进行一些增删改查的操作，使管理状态的逻辑占据组件的大部分主体，时组件变得更加复杂了，所以应该将状态管理的逻辑单独放入一个地方进行管理，方便了后续需的维护。

使用 useReducer 可以帮助开发者更好的分离组件状态管理逻辑和用户界面渲染逻辑，使代码分离。

#### 2.1 工作方式

![useReducer](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/20210219093952144.png)

- action 对象：用于描述组件状态要执行什么的操作
- reducer 方法：用于对状态的集中管理和操作的地方
- store 对象：用于设置初始状态和通过reducer方法修改完后传入store对象并修改
- dispatch 方法：用于触发对象状态的操作

#### 2.2 基本使用

~~~react
//正常使用
const [state,dispatch]=useReducer(reducer,initState);
//惰性初始化
const [state, dispatch] = useReducer(reducer, initialArg, init);
~~~

 它接收一个形如 (state, action) => newState 的 reducer和一个初始值。当然这个初始值也可以通过一个函数计算出来，也就是惰性初始化。如果做惰性初始化，那么useReducer就传递了三个参数，第一个参数依旧是reducer，第三个参数是一个初始化函数，第二个参数是初始化函数要传递的参数列表。

 尽管 useReducer 是扩展的 hook， 而 useState 是基本的 hook，但 useState 实际上执行的也是一个 useReducer。这意味着 useReducer 是更原生的，你能在任何使用 useState 的地方都替换成使用 useReducer。

##### 1. 案例：计数器

~~~react
import { useReducer } from "react";

function reducer(state, action) {
  switch (action.type) {
    case "increment":
      return state + 1;
    case "decrement":
      return state - 1;
    default:
      return state;
  }
}

function Counter() {
  const [count, dispatch] = useReducer(reducer, 0);
  return (
    <>
      <button onClick={() => dispatch({ type: "increment" })}>{count}</button>
      <button onClick={() => dispatch({ type: "decrement" })}>{count}</button>
    </>
  );
}

export default Counter;
~~~

### 3. useLayoutEffect

`useLayoutEffect` 和 `useEffect` 两个方法的作用和使用方式都是一样的，都是用来处理副作用代码的，它们之间唯一的区别就是回调函数的执行时机不同。

`useEffect 执行时机：`

![useEffect](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/31.png)

`useEffect` 在组件视图更新完成后执行，组件状态发生变化 -> 比较状态差异 -> 视图更新 -> useEffect

`useLayoutEffect 执行时机：`

![useLayoutEffect](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/32.png)

`useLayoutEffect` 在组件视图更新前执行，组件状态发生变化 -> 比较状态差异 -> useEffectLayout -> 更新视图

#### 3.1 基础使用

`问题代码：`

~~~react
import { useLayoutEffect, useRef, useState } from "react";

function App() {
  const [isShow, setIsShow] = useState(false);
  const divRef = useRef();
  useEffect(() => {
    if (!divRef.current) return;
    divRef.current.style.top = "100px";
  }, [isShow]);
  return (
    <>
      <button onClick={() => setIsShow(!isShow)}>button</button>
      {isShow ? (
        <div ref={divRef} style={{ position: "absolute" }}>
          div
        </div>
      ) : null}
    </>
  );
}
~~~

问题：

- 在使用 useEffect 会出现元素的闪烁问题，即，在页面初始渲染完成后元素声称在该位置，当用户点击按钮进行位置的修改时先渲染初始状态位置，然后开始渲染 useEffect 内部 DOM 操作。

~~~react
import { useLayoutEffect, useRef, useState } from "react";

function App() {
  const [isShow, setIsShow] = useState(false);
  const divRef = useRef();
  useLayoutEffect(() => {
    if (!divRef.current) return;
    divRef.current.style.top = "100px";
  }, [isShow]);
  return (
    <>
      <button onClick={() => setIsShow(!isShow)}>button</button>
      {isShow ? (
        <div ref={divRef} style={{ position: "absolute" }}>
          div
        </div>
      ) : null}
    </>
  );
}
~~~

使用 useLayoutEffect 后，代码在更新时先进行 useLayoutEffect 内部 DOM 操作后在开始组件的状态渲染。

### 4. UseRef

> 目标：
>
> 1. 获取 DOM 对象
> 2. useRef 缓存数据

`使用方法：`

~~~react
const refContainer = useRef(initialValue);
~~~

通过 useRef 方法返回一个可变的 ref 对象，其 `current` 属性被初始化为传入的参数（initialValue）。

它保存的数据脱离组件的渲染，当组件在重新渲染后仍然存在保持不变。

#### 4.1 获取 DOM 对象

~~~react
import React, { useRef } from "react";
function Example() {
  const divRef = useRef();
  function changeDOM() {
    // 获取整个div
    console.log("整个div", divRef.current);
    // 获取div的class
    console.log("div的class", divRef.current.className);
    // 获取div自定义属性
    console.log("div自定义属性", divRef.current.getAttribute("data-clj"));
  }
  return (
    <div>
      <div className="div-class" data-clj="我是div的自定义属性" ref={divRef}>
        我是div
      </div>
      <button onClick={(e) => changeDOM()}>获取DOM</button>
    </div>
  );
}
export default Example;
~~~

useRef, 它有一个参数可以作为缓存数据的初始值，返回值可以被 DOM 元素 ref 标记，可以获取被标记的元素节点。

#### 4.2 useRef 缓存数据

useEffect、useReducer 这两个 hooks 都可以保存当前数据源，但是如果当执行更新操作后，整体组件会进行重新的渲染，函数内部声明的状态也会被重置；如果想要保存数据且不触发函数的更新则可以使用 useRef 方法。

~~~react
import React, { useRef, useState, useEffect } from "react";
function Example() {
  const [count, setCount] = useState(0);

  const numRef = useRef(count);

  useEffect(() => {
    numRef.current = count;
  }, [count]);

  return (
    <div>
      <h2>count上一次的值: {numRef.current}</h2>
      <h2>count这一次的值: {count}</h2>
      <button onClick={(e) => setCount(count + 10)}>+10</button>
    </div>
  );
}
export default Example;
~~~

当 ref 对象内容发生辩护啊使， useRef 不会通知变更 `.current` 属性不会引发组件的重渲染。

问题：能不能不使用 useRef 方法而使用 useState 方法记录组件渲染次数 ?

答案是不能，因为通过 `useState` 方法声明的是组件状态，组件状态被改变会触发视图更新，一旦视图更新就要通过 count 记录更新次数，count 被改变又会触发视图更新，从而引发组件的无限次循环渲染。

### 5. memo

> 目标：
>
> 1. memo 详情
> 2. memo 使用

问题代码：

`父组件：`

~~~react
import { useEffect, useState } from "react";
import ShowName from "./ShowName";

function App() {
  const [index, setIndex] = useState(0);
  useEffect(() => {
    const timer = setInterval(() => {
      setIndex((prev) => prev + 1);
    }, 1000);
    return () => clearInterval(timer);
  }, []);
  return (
    <>
      <p>{index}</p>
      <ShowName name="张三" />
    </>
  );
}

export default App;
~~~

`子组件：`

~~~react
// src/ShowName.js
import { useEffect } from "react";

function ShowName({ name }) {
  useEffect(() => {
    console.log("ShowName rendered");
  });
  return <div>{name}</div>;
}

export default ShowName;
~~~

问题：

- 每当父组件引起更新时，子组件也会随之更新但是子组件本身没有任何变化

浪费了性能，子组件可在数据没有变化的情况应该保持不变。

#### 5.1 memo 详情

React.memo(...)`是React v16.6引进来的新属性。它的作用和`React.PureComponent`类似，是用来控制函数组件的重新渲染的。`React.memo(...)` 其实就是函数组件的`React.PureComponent

#### 5.2 memo 使用

memo 方法可以为组件添加输入数据 (props) 的比对逻辑，如果当前渲染时的输入数据和上一次渲染时的输入数据一致，阻止组件重新渲染。

```react
import { memo } from "react";

export default memo(ShowName);
```

memo 方法内部采用的是浅层比较，比较基本数据类型的值是否相同，比较引用类型是否为相同的引用地址。

以下代码在父组件每次重新渲染时都会生成新的 person 对象，memo 方法在内部比较时每次得到的都是不同的对象，所以每次子组件也会跟着重新渲染。

```react
<ShowPerson person={{ name: "张三" }} />
```

memo 方法的第二个参数即为比较函数，可以通过它解决以上问题。比较函数的第一个参数为 prevProps，比较函数的第二个参数为 nextProps, 比较函数返回 true 不进行渲染，比较函数返回 false 组件重新渲染。

```react
export default memo(ShowName, compareFunction);

function compareFunction(prevProps, nextProps) {
  if (prevProps.person.name === nextProps.person.name) {
    return true;
  }
  return false;
}
```

### 6. useMemo

> 目标：
>
> 1. useMemo 详情
> 2. useMemo 使用

问题代码：

~~~react
import { useState } from "react";

function App() {
  const [number, setNumber] = useState(0);
  const [dark, setDark] = useState(false);
  const styles = {
    background: dark ? "black" : "white",
    color: dark ? "white" : "black",
  };
  const double = slowFunction(number);
  return (
    <div>
      <input
        type="number"
        value={number}
        onChange={(event) => setNumber(event.target.value)}
      />
      <div style={styles} onClick={() => setDark(!dark)}>
        {double}
      </div>
    </div>
  );
}

function slowFunction(n) {
  for (let i = 0; i < 1000000000; i++) {}
  return n * 2;
}

export default App;
~~~

问题：

- 在每次组件重新渲染时都会区执行 `slowFunction` 函数
- 函数内部的循环没有进行值的修改
- 使得每次渲染都要走循环，浪费了极大的性能

#### 6.1 useMemo 详情

通过 `useMemo` 方法可以对组件中的值进行缓存，就是说在每次组件重新渲染时都返回相同的值，也可以指定哪些状态发生改变时重新计算该值。

`useMemo` 有助于避免在每个渲染上进行昂贵的计算，提升组件性能。

#### 6.2 useMemo 使用

~~~react
import { useEffect, useMemo, useState } from "react";

function App() {
  const [number, setNumber] = useState(0);
  const [dark, setDark] = useState(false);
  const double = useMemo(() => {
    return slowFunction(number);
  }, [number]);
  const styles = useMemo(() => {
    return {
      background: dark ? "black" : "white",
      color: dark ? "white" : "black",
    };
  }, [dark]);
  useEffect(() => {
    console.log("styles");
  }, [styles]);
  return (
    <div>
      <input
        type="number"
        value={number}
        onChange={(event) => setNumber(event.target.value)}
      />
      <div style={styles} onClick={() => setDark(!dark)}>
        {double}
      </div>
    </div>
  );
}

function slowFunction(n) {
  for (let i = 0; i < 1000000000; i++) {}
  return n * 2;
}

export default App;
~~~

### 7. useCallback

> 目标：
>
> 1. useCallback 详情
> 2. useCallback 使用

#### 7.1 useCallback 详情

~~~react
const memoizedCallback = useCallback(
  () => {
    doSomething(a, b);
  },
  [a, b],
);
~~~

返回一个 [memoized] 回调函数。

把 内联回调函数及依赖像数组作为参数传入 `useCallback`，它将返回该回调函数的 memoized 版本，该回调函数仅在某个依赖项改变时才会更新。当你把回调函数传递给经过优化的并使用引用相等性去避免非必要渲染（例如 `shouldComponentUpdate`）的子组件时，它将非常有用。

通过 `useCallback` 方法可以缓存函数，使用组件每次重新渲染都返回相同的函数实例，也可以指定当某个状态发生变化后返回新的函数实例。

问题代码：

~~~react
import { useEffect, useState } from "react";

function App() {
  const [number, setNumber] = useState(1);
  const [dark, setDark] = useState(false);
  const styles = {
    background: dark ? "black" : "white",
    color: dark ? "white" : "black",
  };
  const getItems = () => {
    return [number, number + 1, number + 2];
  };
  return (
    <div style={styles}>
      <input
        type="number"
        value={number}
        onChange={() => setNumber((prev) => prev + 1)}
      />
      <button onClick={() => setDark((dark) => !dark)}>button</button>
      <List getItems={getItems} />
    </div>
  );
}

function List({ getItems }) {
  const [items, setItems] = useState([]);
  
  useEffect(() => {
    setItems(getItems());
    console.log("update items");
  }, [getItems]);

  return (
    <div>
      {items.map((item) => (
        <p key={item}>{item}</p>
      ))}
    </div>
  );
}

export default App;
~~~

问题：

- 每次组件重渲染都会生成一个新的 `getItems` ，List 接受的值都是不一样的 `getItems` 方法
- 当点击按钮时，List 组件无变化但是也会重新渲染
- 当 `getItems` 变化时，styles 会重新生成

#### 7.2 useCallback 使用

~~~react
import { useCallback } from "react";

function App () {
  const getItems = useCallback(() => {
    return [number, number + 1, number + 2];
  }, [number]);
}
~~~

### 8. useImperativeHandle

> 目标：
>
> 1. useImperativeHandle 详情
> 2. useImperativeHandle 使用

#### 8.1 useImperativeHandle 详情

虽然 React 遵循单项数据流原则，但React 也提供了子组件向父组件传递数据方法。

通过 `useImperativeHandle` 方法可以实现父组件获取子组件的数据或者调用子组件的里声明的函数。

父组件通过 useRef 方法创建了一个钩子，用于钩取子组件的数据，子组件在获取到钩子以后，通过 useImperativeHandle 向钩子上暴露数据。

#### 8.1 useImperativeHandle 使用

`父组件：`

~~~react
import { useRef } from "react";
import Message from "./Message";

function App() {
  const messageRef = useRef();
  const onClickHandler = () => {
    console.log(messageRef.current.getText());
    console.log(messageRef.current.input);
  };
  return (
    <>
      <Message ref={messageRef} />
      <button onClick={onClickHandler}>button</button>
    </>
  );
}

export default App;
~~~

`子组件：`

~~~react
import { forwardRef, useImperativeHandle, useRef, useState } from "react";

function Message(props, ref) {
  const [text, setText] = useState("");
  const inputRef = useRef();
  // 参数一：获取 对应元素DOM对象
  // 参数二：回调函数，返回对象方法
  useImperativeHandle(ref, () => {
    return {
      getText() {
        return text;
      },
      input: inputRef.current,
    };
  });
  return (
    <input
      ref={inputRef}
      type="text"
      value={text}
      onChange={(event) => setText(event.target.value)}
    />
  );
}

// 将 forwardRef 包裹住整个组件
export default forwardRef(Message);
~~~

### 9. Custom Hooks

收录了部分常用且实用的自定义Hooks

[Custom Hooks]: https://usehooks.com/	"usehooks"

#### 9.1 useToggle Hooks

该钩子函数的主要作用就是用来接收一个布尔值的参数，并将该值进行切换为相反的值，主要的案例如：显示和隐藏，显示更多/显示更少文本，打开或关闭菜单栏。

>Basically, what this hook does is that, it takes a parameter with value true or false and toggles that value to opposite. It's useful when we want to take some action into it's opposite action, for example: show and hide modal, show more/show less text, open/close side menu. 

JavaScript 写法：

~~~javascript
// Hook
import { useCallback, useState } from 'react';
// Parameter is the boolean, with default "false" value
// 参数为布尔值，默认为 false
const useToggle = (initialState = false) => {
    // Initialize the state
    // 初始化状态
    const [state, setState] = useState(initialState);
    
    // Define and memorize toggler function in case we pass down the component,
    // This function change the boolean value to it's opposite value
    // 实用 useCallback 优化钩子函数，并且该方法将获取的布尔值取反
    const toggle = useCallback(() => setState(state => !state), []);
    // 返回数组状态
    return [state, toggle]
}

// 导出方法
export default useToggle;
~~~

TypeScript 写法：

~~~typescript
// Hook
import { useCallback, useState } from 'react';
// Parameter is the boolean, with default "false" value
// 参数为布尔值，默认为 false
const useToggle = (initialState: boolean = false): [boolean, any] => {
    // Initialize the state
    // 初始化状态
    const [state, setState] = useState<boolean>(initialState);
    
    // Define and memorize toggler function in case we pass down the component,
    // This function change the boolean value to it's opposite value
    // 实用 useCallback 优化钩子函数，并且该方法将获取的布尔值取反
    const toggle = useCallback((): void => setState(state => !state), []);
    // 返回数组状态
    return [state, toggle]
}

// 导出方法
export default useToggle;
~~~

使用：

~~~jsx
// Usage
import useToggle from "@/hooks/useToggle";
function App() {
    // Call the hook which returns, current value and the toggler function
    // useToggle 的返回值为数组
    const [isTextChanged, setIsTextChanged] = useToggle();
    
    return (
        // 点击后进行 button 文字切换
        <button onClick={setIsTextChanged}>{isTextChanged ? 'Toggled' : 'Click to Toggle'}</button>
    );
}
~~~

#### 9.2 useMemoCompare Hooks



> This hook is similar to [useMemo](https://reactjs.org/docs/hooks-reference.html#usememo), but instead of passing an array of dependencies we pass a custom compare function that receives the previous and new value. The compare function can then compare nested properties, call object methods, or anything else to determine equality. If the compare function returns true then the hook returns the old object reference.
>
> It's worth noting that, unlike useMemo, this hook isn't meant to avoid expensive calculations. It needs to be passed a computed value so that it can compare it to the old value. Where this comes in handy is if you want to offer a library to other developers and it would be annoying to force them to memoize an object before passing it to your library. If that object is created in the component body (often the case if it's based on props) then it's going to be a new object on every render. If that object is a `useEffect` dependency then it's going to cause the effect to fire on every render, which can lead to problems or even an infinite loop. This hook allows you to avoid that scenario by using the old object reference instead of the new one if your custom comparison function deems them equal.
>
> Read through the recipe and comments below. For a more practical example be sure to check out our **useFirestoreQuery** hook.

JavaScript 写法：

~~~javascript
import React, { useEffect, useRef } from "react";

// Hook
function useMemoCompare(next, compare) {
  // Ref for storing previous value
  const previousRef = useRef();
  const previous = previousRef.current;
  // Pass previous and next value to compare function
  // to determine whether to consider them equal.
  const isEqual = compare(previous, next);
  // If not equal update previousRef to next value.
  // We only update if not equal so that this hook continues to return
  // the same old value if compare keeps returning true.
  useEffect(() => {
    if (!isEqual) {
      previousRef.current = next;
    }
  });
  // Finally, if equal then return the previous value
  return isEqual ? previous : next;
}
~~~

用法：

~~~jsx
import React, { useState, useEffect } from "react";

// Usage
function MyComponent({ obj }) {
  const [state, setState] = useState();
  // Use the previous obj value if the "id" property hasn't changed
  const objFinal = useMemoCompare(obj, (prev, next) => {
    return prev && prev.id === next.id;
  });
  // Here we want to fire off an effect if objFinal changes.
  // If we had used obj directly without the above hook and obj was technically a
  // new object on every render then the effect would fire on every render.
  // Worse yet, if our effect triggered a state change it could cause an endless loop
  // where effect runs -> state change causes rerender -> effect runs -> etc ...
  useEffect(() => {
    // Call a method on the object and set results to state
    return objFinal.someMethod().then((value) => setState(value));
  }, [objFinal]);
  // So why not pass [obj.id] as the dependency array instead?
  useEffect(() => {
    // Then eslint-plugin-hooks would rightfully complain that obj is not in the
    // dependency array and we'd have to use eslint-disable-next-line to work around that.
    // It's much cleaner to just get the old object reference with our custom hook.
    return obj.someMethod().then((value) => setState(value));
  }, [obj.id]);
  return <div> ... </div>;
}
~~~





#### 9.3 useFirestoreQuery Hooks

该钩子函数可以让我们更方便的更新数据且不必担心状态管理，我们朱旭将一个查询传递到 useFirestoreQuery() 函数中，就可以获取到数据、状态、和错误信息。当数据更改时，组件将重新渲染；当组件卸载时数据会自动删除。

> This hook makes it super easy to subscribe to data in your Firestore database without having to worry about state management. Instead of calling Firestore's `query.onSnapshot()` method you simply pass a query to `useFirestoreQuery()` and you get back everything you need, including `status`, `data`, and `error`. Your component will re-render when data changes and your subscription will be automatically removed when the component unmounts. Our example even supports dependent queries where you can wait on needed data by passing a falsy value to the hook. Read through the recipe and comments below to see how it works.

JavaScript 写法：

`reducer.js`

~~~javascript
// Reducer for hook state and actions
// 全局状态共享
const reducer = (state, action) => {
  // 获取到传来的状态进行判断
  switch (action.type) {
    case "idle":
      return { status: "idle", data: undefined, error: undefined };
    case "loading":
      return { status: "loading", data: undefined, error: undefined };
    case "success":
      return { status: "success", data: action.payload, error: undefined };
    case "error":
      return { status: "error", data: undefined, error: action.payload };
    default:
      throw new Error("invalid action");
  }
};
// 导出
export default reducer;
~~~

`useFirestoreQuery.js`

~~~javascript
import reducer from "@/store/reducer"
// Hook
function useFirestoreQuery(query) {
  // Our initial state
  // Start with an "idle" status if query is falsy, as that means hook consumer is
  // waiting on required data before creating the query object.
  // Example: useFirestoreQuery(uid && firestore.collection("profiles").doc(uid))
  // 定义初始化数据：
  //	1. status： query（请求）loading为正在加载，idle为默认状态
  const initialState = {
    status: query ? "loading" : "idle",
    data: undefined,
    error: undefined,
  };
  // Setup our state and actions
  // 设置状态
  const [state, dispatch] = useReducer(reducer, initialState);
  // Get cached Firestore query object with useMemoCompare (https://usehooks.com/useMemoCompare)
  // Needed because firestore.collection("profiles").doc(uid) will always being a new object reference
  // causing effect to run -> state change -> rerender -> effect runs -> etc ...
  // This is nicer than requiring hook consumer to always memoize query with useMemo.
  const queryCached = useMemoCompare(query, (prevQuery) => {
    // Use built-in Firestore isEqual method to determine if "equal"
    return prevQuery && query && query.isEqual(prevQuery);
  });
  useEffect(() => {
    // Return early if query is falsy and reset to "idle" status in case
    // we're coming from "success" or "error" status due to query change.
    if (!queryCached) {
      dispatch({ type: "idle" });
      return;
    }
    dispatch({ type: "loading" });
    // Subscribe to query with onSnapshot
    // Will unsubscribe on cleanup since this returns an unsubscribe function
    return queryCached.onSnapshot(
      (response) => {
        // Get data for collection or doc
        const data = response.docs
          ? getCollectionData(response)
          : getDocData(response);
        dispatch({ type: "success", payload: data });
      },
      (error) => {
        dispatch({ type: "error", payload: error });
      }
    );
  }, [queryCached]); // Only run effect if queryCached changes
  return state;
}
// Get doc data and merge doc.id
function getDocData(doc) {
  return doc.exists === true ? { id: doc.id, ...doc.data() } : null;
}
// Get array of doc data from collection
function getCollectionData(collection) {
  return collection.docs.map(getDocData);
}
~~~

使用：

~~~jsx
// Usage
function ProfilePage({ uid }) {
  // Subscribe to Firestore document
  const { data, status, error } = useFirestoreQuery(
    firestore.collection("profiles").doc(uid)
  );
  if (status === "loading") {
    return "Loading...";
  }
  if (status === "error") {
    return `Error: ${error.message}`;
  }
  return (
    <div>
      <ProfileHeader avatar={data.avatar} name={data.name} />
      <Posts posts={data.posts} />
    </div>
  );
}
~~~





### 10. Children

> 目标：
>
> 1. only
> 2. count
> 3. map
> 4. toArray

`Children` 和 `children` 不一样，`children` 通常用作为布局组件，而 `Children` 指的是布局组件内部的元素，可以为 JSX、函数、对象等等，并对其进行操作。

#### 10.1 only 方法

通过 `Children.only` 方法可以限制组件标签只接收一个子元素。

`父组件：`

~~~react
import Message from "./Message";

function App() {
  // 不允许 Message 组件标签传入多个子元素, 需要对这种情况进行限制
  return (
    <Message>
      <p>Hello</p>
      <p>Hello</p>
    </Message>
  );
}
~~~

对 Message 组件进行限制

`子组件：`

~~~react
import { Children } from "react";

function Message(props) {
  try {
    Children.only(props.children);
  } catch (error) {
    // Error: React.Children.only expected to receive a single React element child.
    // 错误: React.children 只期望接收一个 React 元素
    return <div>Message 组件标签只接收一个子元素 </div>;
  }
  return <div>{props.children}</div>;
}
~~~

#### 10.2 count 方法

通过 `Children.count` 方法可以获取组件标签传入的子元素的数量。

```react
import { Children } from "react";

function Message(props) {
  return <div>{Children.count(props.children)}</div>;
}
```

#### 10.3 map 方法

通过 `Children.map` 方法可以对组件标签内部的子元素进行转换操作。

~~~react
import Message from "./Message";

function App() {
  return (
    <Message>
      <p>Hello</p>
      <p>Hello</p>
    </Message>
  );
}
~~~

通过遍历后再给元素添加父组件

~~~react
import { Children } from "react";

function Message(props) {
  const items = Children.map(props.children, (item) => (
    <a href="http://www.baidu.com">{item}</a>
  ));
  return <div>{items}</div>;
}
~~~

#### 10.4 toArray 方法

`props.children` 存储多个值时是数组类型，存储一个值时为对象类型。

通过 `Children.toArray` 方法可以将 `props.children` 转换为数组类型，以保证 `Children.map` 方法永远有用。

~~~react
// src/App.js
import ImageToggle from "./ImageToggle";

function App() {
  return (
    <ImageToggle>
      <img
        src="https://images.pexels.com/photos/10198426/pexels-photo-10198426.jpeg"
        alt=""
        width="300px"
      />
      <img
        src="https://images.pexels.com/photos/4386364/pexels-photo-4386364.jpeg"
        alt=""
        width="300px"
      />
      <img
        src="https://images.pexels.com/photos/9812128/pexels-photo-9812128.jpeg"
        alt=""
        width="300px"
      />
      <img
        src="https://images.pexels.com/photos/8746965/pexels-photo-8746965.jpeg"
        width="300px"
        alt=""
      />
    </ImageToggle>
  );
}
~~~

设置图片自动轮播：

~~~react
// src/ImageToggle.js
import { useEffect, useState, Children } from "react";

function ImageToggle(props) {
  const [state, setState] = useState({
    // 当前要显示的图片的索引
    current: 0,
    // 总共有多少张图片, 用于索引的溢出判断
    total: 0,
  });
  useEffect(() => {
    setState((prev) => ({ ...prev, total: Children.count(props.children) }));
  }, [props.children]);

  useEffect(() => {
    const timer = setInterval(showNext, 2000);
    return () => clearInterval(timer);
  }, []);

  const showNext = () => {
    setState(({ current, total }) => {
      return {
        total,
        current: current + 1 === total ? 0 : current + 1,
      };
    });
  };
  return <div>{Children.toArray(props.children)[state.current]}</div>;
}
~~~

### 11. Context

通过解决 **跨组件数据共享问题**， 但是后续会有 更好的工具使用。

#### 11.1 已知问题

在 React 中虽然使用 Context 可以方便的实现组件之间的状态共享，但是如果使用不当就会产生严重的性能问题。 

当多个组件使用了 Context 中的不同的状态时，只要 Context 中的某一个状态发生改变，使用了其他状态的其他组件也会重新渲染。

```react
// src/Context.js
import { createContext, useState } from "react";

export const AppContenxt = createContext();

export function AppProvider({ children }) {
  const [state, setState] = useState({
    foo: "foo context",
    bar: "bar context",
  });
  return (
    <AppContenxt.Provider value={[state, setState]}>
      {children}
    </AppContenxt.Provider>
  );
}
```

```react
// src/App.js
import Bar from "./Bar";
import Foo from "./Foo";
import { AppProvider } from "./Context";

function App() {
  return (
    <AppProvider>
      <Foo />
      <Bar />
    </AppProvider>
  );
}

export default App;
```

```react
// src/Foo.js
import { useContext, useEffect } from "react";
import { AppContenxt } from "./Context";

function Foo() {
  const [appContext, setAppContext] = useContext(AppContenxt);
  useEffect(() => {
    console.log("Foo render");
  });
  const onClickHandler = () => {
    setAppContext((state) => ({ ...state, foo: "foo contenxt changed" }));
  };
  return (
    <div>
      {appContext.foo} <button onClick={onClickHandler}>foo button</button>
    </div>
  );
}

export default Foo;
```

```react
// src/Bar.js
import { useContext, useEffect } from "react";
import { AppContenxt } from "./Context";

function Bar() {
  const [appContext] = useContext(AppContenxt);
  useEffect(() => {
    console.log("Bar render");
  });
  return <div>{appContext.bar}</div>;
}

export default Bar;
```

#### 11.2 解决方案

##### 1. 拆分 Context

```react
// src/FooContext.js
import { createContext, useState } from "react";

export const FooContext = createContext();

export function FooProvider({ children }) {
  const [foo, setFoo] = useState("foo context");
  return (
    <FooContext.Provider value={[foo, setFoo]}>{children}</FooContext.Provider>
  );
}
```

```react
// src/BarContext.js
import { createContext, useState } from "react";

export const BarContext = createContext();

export function BarProvider({ children }) {
  const [bar, setBar] = useState("bar context");
  return (
    <BarContext.Provider value={[bar, setBar]}>{children}</BarContext.Provider>
  );
}
```

```react
// src/App.js
import Bar from "./Bar";
import Foo from "./Foo";
import { BarProvider } from "./BarContext";
import { FooProvider } from "./FooContext";

function App() {
  return (
    <>
      <FooProvider>
        <Foo />
      </FooProvider>
      <BarProvider>
        <Bar />
      </BarProvider>
    </>
  );
}

export default App;
```

```react
// src/Foo.js
import { useContext, useEffect } from "react";
import { FooContext } from "./FooContext";

function Foo() {
  const [foo, setFoo] = useContext(FooContext);
  useEffect(() => {
    console.log("Foo render");
  });
  return (
    <div>
      {foo}
      <button onClick={() => setFoo("foo contenxt changed")}>foo button</button>
    </div>
  );
}

export default Foo;
```

```react
// src/Bar.js
import { useContext, useEffect } from "react";
import { BarContext } from "./BarContext";

function Bar() {
  const [bar] = useContext(BarContext);
  useEffect(() => {
    console.log("Bar render");
  });
  return <div>{bar}</div>;
}

export default Bar;
```

##### 2. 拆分组件

```react
// src/Bar.js
import { memo, useContext, useEffect } from "react";
import { AppContenxt } from "./Context";

const BarContext = memo((props) => {
  useEffect(() => {
    console.log("BarContext render");
  });
  return <div>{props.bar}</div>;
});

function Bar() {
  const [appContext] = useContext(AppContenxt);
  return <BarContext bar={appContext.bar} />;
}

export default Bar;
```

##### 3. 缓存状态

```react
import { useContext, useMemo } from "react";
import { AppContenxt } from "./Context";

function Bar() {
  const [appContext] = useContext(AppContenxt);
  const bar = appContext.bar;
  return useMemo(() => {
    console.log("bar render");
    return <div>{bar}</div>;
  }, [bar]);
}

export default Bar;
```



