class TreeNode[T]:
    def __init__(
        self,
        val: T,
        left: "TreeNode[T] | None" = None,
        right: "TreeNode[T] | None" = None,
    ):
        self.val = val
        self.left = left
        self.right = right

    @classmethod
    def from_list(cls, arr: list[T | None]) -> "TreeNode[T] | None":
        """Convert array representation to binary tree."""
        if not arr or arr[0] is None:
            return None

        root = cls(arr[0])
        queue = [root]
        i = 1

        while queue and i < len(arr):
            node = queue.pop(0)

            if i < len(arr) and arr[i] is not None:
                left_val = arr[i]
                assert left_val is not None
                node.left = cls(left_val)
                queue.append(node.left)
            i += 1

            if i < len(arr) and arr[i] is not None:
                right_val = arr[i]
                assert right_val is not None
                node.right = cls(right_val)
                queue.append(node.right)
            i += 1

        return root

    def to_list(self) -> list[T | None]:
        """Convert binary tree to array representation."""
        result: list[T | None] = []
        queue: list[TreeNode[T] | None] = [self]

        while queue:
            node = queue.pop(0)
            if node:
                result.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append(None)

        # Remove trailing None values
        while result and result[-1] is None:
            result.pop()

        return result

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, TreeNode):
            return False
        return self.to_list() == other.to_list()

    def find_node(self, val: T) -> "TreeNode[T] | None":
        """Find node with given value."""
        if self.val == val:
            return self
        if self.left:
            left_result = self.left.find_node(val)
            if left_result:
                return left_result
        if self.right:
            return self.right.find_node(val)
        return None

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.to_list()})"
