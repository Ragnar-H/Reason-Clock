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

let numbers: array(Numbers.option) = [|
  {value: "24", key: "1"},
  {value: "56", key: "3"},
  {value: "57", key: "4"},
|];

let app = () =>
  <View style=Styles.container>
    <Numbers options=numbers />
    <Numbers options=numbers />
    <Numbers options=numbers />
  </View>;