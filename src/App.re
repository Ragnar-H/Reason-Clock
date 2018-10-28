open BsReactNative;

let numbers: array(Numbers.option) = [|
  {value: "24", key: "1"},
  {value: "56", key: "3"},
  {value: "57", key: "4"},
|];

let app = () =>
  <View>
    <Numbers options=numbers />
    <Text> {ReasonReact.string("Let's get this party started!")} </Text>
  </View>;