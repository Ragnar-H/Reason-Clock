open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.),
      flexDirection(Row),
      justifyContent(Center),
      backgroundColor(String("#524078")),
    ]);
};

let createOption = (~value: int): Numbers.option => {
  value: string_of_int(value),
  key: string_of_int(value),
};

let rec createOptionTo = (~length: int) =>
  if (length <= 0) {
    [];
  } else {
    [createOption(~value=length), ...createOptionTo(~length=length - 1)];
  };

let hours = createOptionTo(~length=24);
let minutes = createOptionTo(~length=60);
let seconds = createOptionTo(~length=60);

type state = {
  date: Js.Date.t,
  timerIntervalId: ref(option(Js.Global.intervalId)),
};

type action =
  | Tick;

let component = ReasonReact.reducerComponent("Clock");
/* Heavy use of https://github.com/reasonml/reason-react/blob/master/docs/counter.md */
/* https://reasonml.github.io/reason-react/docs/en/subscriptions-helper#docsNav */

let make = _children => {
  ...component,
  initialState: () => {date: Js.Date.make(), timerIntervalId: ref(None)},
  reducer: (action, state) =>
    switch (action) {
    | Tick => ReasonReact.Update({...state, date: Js.Date.make()})
    },
  didMount: self =>
    self.state.timerIntervalId :=
      Some(Js.Global.setInterval(() => self.send(Tick), 1000)),
  willUnmount: self =>
    switch (self.state.timerIntervalId^) {
    | Some(id) => Js.Global.clearInterval(id)
    | None => ()
    },
  render: self => {
    /* Cast to int to strip trailing . */
    let currentHour = int_of_float(Js.Date.getHours(self.state.date));
    let currentMinute = int_of_float(Js.Date.getMinutes(self.state.date));
    let currentSecond = int_of_float(Js.Date.getSeconds(self.state.date));

    <View style=Styles.container>
      <Numbers selectedValue={string_of_int(currentHour)} options=hours />
      <Numbers selectedValue={string_of_int(currentMinute)} options=minutes />
      <Numbers selectedValue={string_of_int(currentSecond)} options=seconds />
    </View>;
  },
};