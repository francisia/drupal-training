<?php
/**
 * @file
 * Theme template for jdt_user_notes template
 */

?>

<div class='jdt-user-notes-template'>
  <?php if (count($note_list)) : ?>
  <table>
    <tr>
      <th>Note</th>
      <th>Actions</th>
    </tr>
    <?php foreach($note_list as $note): ?>
    <tr>
      <td><?php print $note->note_text ?></td>
      <td><a href='../../note/<?php print $note->note_id ?>/edit'>Edit</a></td>
    </tr>
    <?php endforeach; ?>
  </table>
  <?php else: ?>
  <p>No notes available for this article</p>
  <?php endif; ?>
</div>
