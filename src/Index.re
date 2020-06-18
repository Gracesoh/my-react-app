// Entry point

[@bs.val] external document: Js.t({..}) = "document";

// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= ExampleStyles.style;

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

let id = x => ZEDLang.Lam({vid: x, exp: Lift(Var(x))});

ReactDOMRe.render(
  <VizTrace
    program={ZEDLang.Let("x", Num(5), Lift(Add(App(id("y"), Var("x")), Num(1))))}
  />,
  makeContainer("Demo. See state 17."),
);