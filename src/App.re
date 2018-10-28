open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.),
      flexDirection(Row),
      justifyContent(Center),
      alignItems(Center),
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

let app = () =>
  <View style=Styles.container>
    <Numbers options=hours />
    <Numbers options=minutes />
    <Numbers options=seconds />
  </View>;