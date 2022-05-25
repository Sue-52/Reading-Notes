---
title: React Immutable data -- React 不可变数据结构
date: 2022-04-14 21:45:00
categories:
  - React
tags:
  - React
---

## 不可变数据结构

### 1. 概述

不可变数据结构是指在更改变量时不在原有值的基础上进行修改而是创建一个新值重新赋值给变量。

不可变数据结构使应用程序更加稳定，比如将对象传递给一个函数，不必担心函数执行完成后该对象是否仍然具有相同的值。

```javascript
var name = "张三";
name = "李四";
```

![55](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/55.png)

![56](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/56.png)

```javascript
var IDCard = {name: "张三"};

function createNewIdCard() {
  IDCard.name = "李四"
}

IDCard // ?
```

### 2. JS 中的数据不可变

JavaScript 这门编程语言并不具备完全的数据不可变特性。

在 JavaScript 中，基本数据类型完全遵循了数据的不可变特性，而引用数据类型并没有完全遵循。

#### 2.1 基本数据类型

```javascript
var nameOne = "张三";
var nameTwo = nameOne;
nameOne = "李四";
// nameTwo ?
```

由于在 JavaScript 中基本数据类型遵循了数据的不可变特性，更改变量值时并没有在原有值"张三"的基础上进行修改，而是创建了一个新值，然后将新值重新赋值给变量，所以 nameTwo 变量仍然指向"张三"这个值。

![57](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/57.png)

![58](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/58.png)

#### 2.2 引用数据类型

```javascript
var p1 = {name: "张三"};
p1 = {name: "李四"};
```

![61](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/61.png)

![62](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/62.png)

```javascript
var p1 = { name: '张三' };
var p2 = p1;
p2.name = '李四';
p1.name // ?
```

![59](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/59.png)

![60](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/60.png)

在以上代码中，更改 p2 变量时并没有重新为 p2 变量赋值而是对已有值进行了更改，由于变量 p1 和变量 p2 指向了同一个对象，所以对 p2 变量进行的更改也影响到了 p1 变量。

这种情况在程序世界中被称之为数据突变，这是相对于数据的不可变特性而言的，数据突变带来的结果就是程序的不稳定性，所以在编写 JavaScript 应用程序时要时刻确保不要发生数据突变。

### 3. JS 中避免数据突变的方式

#### 3.1 对象

如果是简单对象，即不包含对象嵌套对象，在修改对象值时最简单的避免数据突变的方式就是使用扩展运算符将原有对象属性展开到新的对象中。

```javascript
var person = {name: "张三", age: 20};
var modifiedPerson = {...person, age: 50};
```

如果是复杂对象，即包含了对象嵌套对象，在修改对象值时要对原有对象进行深拷贝，在拷贝出来的新对象中进行修改。

```javascript
const data = { "name": "居家", "goods": [{"name": "暖腰暖腹暖胃，蕲艾暖宫腰带"}]};
const newData = deepClone(data);
newData.name = "海鲜";
```

复杂对象不能使用扩展运算符的原因是扩展运算符是浅拷贝，对于内层嵌套对象来说不能起到拷贝的作用。

```javascript
const state = [{ name: "super me" }];
const newState = state.slice(0);
newState[0].name = "李四"

console.log("state:", state) // state: [{name: "李四}]
```

#### 3.2 数组

对于 JavaScript 数组来说，目前既提供了数据突变方法，又提供了数据不可变方法，在实际编程中推荐使用数据不可变方法。

sort、splice、push、pop 等就属于数据突变方法。

```javascript
const a = [2, 1, 4, 3]
const b = a.sort()
console.log(b) // [1, 2, 3, 4]
console.log(a) // [1, 2, 3, 4]
```

map、filter、reduce、slice 等就属于数据不可变方法。

```javascript
const before = ["a", "b", "c", "d"]
const after = before.slice(0, 2)
console.log(after) // ["a", "b"]
console.log(before) // ["a", "b", "c", "d"]
```

JavaScript 中的扩展运算符也可以比较方便的实现数据的不可变特性。

```javascript
// 向数组中添加元素
const before = ["a", "b", "c", "d"]
const after = [...before, "e"]
console.log('after:', after)   // ["a", "b", "c", "d", "e"]
console.log('before:', before) // ["a", "b", "c", "d"]
```

```javascript
// 从数组中删除元素
const before = ["a", "b", "c", "d"]
const after = [...before.slice(0, 2), ...before.slice(3)]
console.log("after:", after)   // ["a", "b", "d"]
console.log("before:", before) // ["a", "b", "c", "d"]
```

```javascript
// 修改数组中的元素
const before = ["a", "b", "c", "d"]
const after = [...before.slice(0, 1), "x", "y", ...before.slice(3)]
console.log("after:", after) //  // ["a", "x, "y", "d"]
console.log("before:", before)  // ["a", "b", "c", "d"]
```

### 4. 目前存在的问题

在数据结构复杂的情况下，比如对象嵌套对象、数组嵌套对象，就必须使用深拷贝，但是使用深拷贝存在两个问题。

第一，深拷贝必须递归遍历所有对象属性，逐层对数据进行拷贝，执行效率低。

第二，进行了深拷贝以后，内存中将会存在很多重复的数据，影响性能。

```javascript
var p1 = {name: '张三', skill: ['编程', '驾驶']};
var p2 = deepClone(p1);
p2.name = '李四';
```

比如在上面的代码中将 p1 进行了深拷贝，p1 和 p2 就变成了两个完全独立的对象，虽然实现了数据不可变特性，但同时在内存中也多出了一份完全相同的 skill 属性值。理想状态应该是两个对象中 name 属性是独立的，skill 属性是共享的。

```javascript
let skill = ['编程', '驾驶']
let p1 = {name: "张三", skill}
let p2 = {name: "李四", skill}
```

### 5. [Immer](https://immerjs.github.io/immer/zh-CN/)

#### 5.1 概述

Immer 是一个 JavaScript 扩展库，可以让开发者方便的实现数据不可变特性，每次操作都会产生一个新的不可变数据，无论这个操作是增加，删除还是修改，都不会影响到原有数据。

Immer 具有数据结构共享特性，在拷贝对象时可以实现不变的属性值在内存中进行共享，变化的属性值与原对象之间完全独立。

Immer 可以让开发者使用数据不可变特性的同时极大提升应用程序的性能。

```bash
npm install immer@9.0.12
```

#### 5.2 基本使用

Immer 向外默认导出了一个 可以完成所有工作的方法即 produce。

```javascript
import produce from "immer";

const baseState = [
  { id: 1, title: "Hello JavaScript", done: true },
  { id: 2, title: "Hello Immer", done: false },
];

const newState = produce(baseState, (draftState) => {
  draftState[1].done = true;
  draftState.push({ id:3, title: "Learn React", done: false });
});
```

案例：封装一个用于切换任务是否完成的方法。

```javascript
function toggleTodo(state, id) {
  return produce(state, (draftState) => {
    const todo = draftState.find((item) => item.id === id);
    todo.done = !todo.done;
  });
}

const newState = toggleTodo(baseState, 2);
```

### 6.  React 与 Immer

#### 6.1 概述

在 React 中，它要求状态必须具有不可变性，即不能直接更改原状态对象，必须创建新的状态对象，使用新的状态对象替换旧的状态对象。

```react
import { useState } from "react";

export default function App() {
  const [person, setPerson] = useState({ name: "张三" });
  const onClickHandler = () => {
    // 此处的状态修改并不会触发视图更新, 原因是违背了数据不可变原则
    person.name = "李四";
    setPerson(person);
    // 正确的做法是创建一个新的状态状态, 传递新状态对象才能触发视图更新
    // const newPerson = { ...person, name: "李四" };
    // setPerson(newPerson);
  };
  return <button onClick={onClickHandler}>{person.name}</button>;
}
```

```react
import { useState } from "react";

export default function App() {
  const [person, setPerson] = useState(["张三"]);
  const onClickHandler = () => {
    // 此处更新并不会触发视图更新, 原因是违背了数据不可变原则
    person.push("李四");
    setPerson(person);
    // 以下为正确用法
    // const newPerson = [...person, "李四"];
    // setPerson(newPerson);
  };
  return <button onClick={onClickHandler}>{person}</button>;
}
```

#### 6.2 在 React 中使用 Immer

##### 1. useState

```react
import { useState } from "react";
import produce from "immer";

export default function App() {
  const [person, setPerson] = useState({ name: "张三" });
  const onClickHandler = () => {
    setPerson(
      produce(person, (draftState) => {
        draftState.name = "李四";
      })
    );
  };
  return <button onClick={onClickHandler}>{person.name}</button>;
}
```

```bash
npm install use-immer
```

```react
import { useImmer } from "use-immer";

export default function App() {
  const [person, setPerson] = useImmer({ name: "张三" });
  const onClickHandler = () => {
    setPerson((draftState) => {
      draftState.name = "李四";
    });
  };
  return <button onClick={onClickHandler}>{person.name}</button>;
}
```

##### 2. useReducer

```react
import { useReducer } from "react";
import produce from "immer";

const reducer = produce((draft, action) => {
  switch (action.type) {
    case "increment":
      draft.count = draft.count + 1;
      break;
  }
});

export default function App() {
  const [state, dispatch] = useReducer(reducer, { count: 0 });
  return <button onClick={() => dispatch({ type: "increment" })}>{state.count}</button>;
}
```

```react
import { useImmerReducer } from "use-immer";

const reducer = (draft, action) => {
  switch (action.type) {
    case "increment":
      draft.count = draft.count + 1;
      break;
  }
};

export default function App() {
  const [state, dispatch] = useImmerReducer(reducer, { count: 0 });
  return <button onClick={() => dispatch({ type: "increment" })}>{state.count}</button>;
}
```

### 7. Immutable

#### 7.1 概述

在 [Immutable.js](https://immutable-js.github.io/immutable-js/) 中提供了多种数据结构用于实现不可变数据，常用的有两种，即 List 和 Map。

List 对应 JavaScript 中的数组。

Map 对应 JavaScript 中的对象。

```bash
npm install immutable@4.0.0
```

```javascript
import { List, Map } from "immutable";

const l1 = new List(["a", "b"]);
console.log(l1);
const m1 = new Map({ a: 1, b: 2 });
console.log(m1);
```

#### 7.2 实例方法

##### 1. 设置数据

```javascript
import { List } from "immutable";

const l1 = new List(["a", "b"]);
const l2 = l1.set(0, "x");
console.log(l2); // List ["x","b"]
console.log(l1); // List ["a", "b"]
```

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: 1, b: 2 });
const m2 = m1.set("a", 100);
console.log(m2); // Map {a: 100, b: 2}
console.log(m1); // Map {a: 1, b: 2}
```

##### 2. 获取数据

```javascript
import { List } from "immutable";

const l1 = new List(["a", "b"]);
console.log(l1.get(0)); // "a"
```

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: 1, b: 2 });
console.log(m1.get("a")); // 1
```

##### 3. 合并数据

```javascript
import { List } from "immutable";

const l1 = new List(["a", "b"]);
const l2 = new List(["c", "d"]);
const l3 = l1.merge(l2);
console.log(l3); // List ["a", "b", "c", "d"]
console.log(l1); // List ["a", "b"]
console.log(l2); // List ["c", "d"]
```

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: 1, b: 2 });
const m2 = new Map({ c: 3, d: 4 });
const m3 = m1.merge(m2);
console.log(m3); // Map {a: 1, b: 2, c: 3, d: 4}
console.log(m1); // Map {a: 1, b: 2}
console.log(m2); // Map {c: 3, d: 4}
```

##### 4. 删除数据

```javascript
import { List } from "immutable";

const l1 = new List(["a", "b"]);
const l2 = l1.remove(0);
console.log(l2); // List ["b"]
console.log(l1); // List ["a", "b"]
```

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: 1, b: 2 });
const m2 = m1.remove("a");
console.log(m2); // Map {b: 2}
console.log(m1); // Map {a: 1, b: 2}
```

##### 5. 更新数据

```javascript
import { List } from "immutable";

const l1 = new List(["a", "b"]);
const l2 = l1.update(0, target => target + "Hello");
console.log(l2); // List ["aHello", "b"]
console.log(l1); // List ["a", "b"]
```

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: 1, b: 2 });
const m2 = m1.update("b", target => target * 2);
console.log(m2); // Map {a: 1, b: 4}
console.log(m1); // Map {a: 1, b: 2}
```

#### 7.3 工具方法

##### 1. 数据类型转换

使用 `fromJS 方法` 将数组和对象转换为不可变数据，数组转为 List，对象转为 Map。

Map 和 List 方法在创建数据时不支持深层嵌套，fromJS 方法支持深层嵌套。

```javascript
import { Map } from "immutable";

const m1 = new Map({ a: { b: { c: 1 } } });
console.log(m1); // Map {"a": [object Object]}
```

```javascript
import { fromJS } from "immutable";

const f1 = fromJS({ a: { b: { c: 1 } } });
console.log(f1); // Map {"a": Map {b: Map {c: 1}}}
```

```javascript
import { fromJS } from "immutable";

const f1 = fromJS({ a: { b: { c: 1 } } });
const f2 = f1.setIn(["a", "b", "c"], 100);
console.log(f2); // Map {"a": Map {b: Map {c: 100}}}
console.log(f1); // Map {"a": Map {b: Map {c: 1}}}
```

##### 2. 数据比对

使用 `is 方法` 判断两个不可变数据是否相同。

```javascript
import { fromJS, is } from "immutable";

const m1 = fromJS({ a: { b: { c: 1 } } });
const m2 = fromJS({ a: { b: { c: 1 } } });
console.log(is(m1, m2)); // true
```

### 8. React 与 Immutable

##### 1. useState

```javascript
import { fromJS } from "immutable";
import { useState } from "react";

export default function App() {
  const [person, setPerson] = useState(fromJS({ name: "张三" }));
  const onClickHandler = () => {
    setPerson(person.set("name", "李四"));
  };
  return <button onClick={onClickHandler}>{person.get("name")}</button>;
}
```

##### 2. Redux

```react
import ReactDOM from "react-dom"
import App from "./App"
import { createStore } from "redux"
import { Provider } from "react-redux"
import { fromJS } from "immutable"

const initialState = fromJS({count: 0 })

function reducer(state = initialState, action) {
  let count = state.get("count")
  switch (action.type) {
    case "increment":
      return state.set("count", count + 1)
    case "decrement":
      return state.set("count", count - 1)
    default:
      return state
  }
}

const store = createStore(reducer)

ReactDOM.render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById("root")
)
```

```react
import { useDispatch, useSelector } from "react-redux"

export default function App() {
  const dispatch = useDispatch()
  const count = useSelector(state => state.get("count"))
  return (
    <>
      <button onClick={() => dispatch({ type: "increment" })}> increment {count} </button>
      <button onClick={() => dispatch({ type: "decrement" })}> decrement {count} </button>
    </>
  )
}
```

